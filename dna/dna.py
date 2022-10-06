import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        for row in reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    sequence = []
    with open(sys.argv[2], 'r') as f:
        read_data = f.read()
        sequence.append(read_data)
    f.closed

    # TODO: Find longest match of each STR in DNA sequence
    m = []
    n = len(database[0])
    for i in range(1, n):
        subseq = database[0][i]
        m.append(longest_match(sequence[0], subseq))

    # TODO: Check database for matching profiles
    count = 0
    k = []
    for i in range(len(database)-1):
        k.append([0]*(n - 1))
    for i in range(1, len(database)):
        for j in range(1, n):
            database[i][j] = int(database[i][j])
            k[i-1][j-1] = database[i][j]

    for i in range(0, len(database) - 1):
        if m == k[i]:
            print(database[i+1][0])
            count += 1

    if (count == 0):
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
