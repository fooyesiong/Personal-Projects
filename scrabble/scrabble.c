#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
string point = "abcdefghijklmnopqrstuvwxyz";
string point2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2){
        printf("Player 1 wins!\n");
    }

    if (score1 < score2){
        printf("Player 2 wins!\n");
    }

    if (score1 == score2){
        printf("Tie!\n");
    }

    // TODO: Print the winner
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int n;
    int sc1 = 0;
    int sumsc1 = 0;
    int k = strlen(word);

    for (n = 0; n < k;){
        if (isupper(word[n])){
            word[n] = toupper(word[n]);
            for (int f = 0; f< strlen(point2); f++){
                if (word[n] == point2[f]){
                    sc1 = POINTS[f];
                    sumsc1 = sumsc1 + sc1;
                    }
            }
        }
        else if (islower(word[n])){
            for (int f = 0; f< strlen(point); f++){
                if (word[n] == point[f]){
                    sc1 = POINTS[f];
                    sumsc1 = sumsc1 + sc1;
                }
            }
        }
        else{
            n += 1;
        }
    n += 1;
    }

    return sumsc1;
}

