#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int only_once(string s);
int check_alpha(string s);

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        if(strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if(only_once(argv[1]) > 0)
        {
            printf("Invalid key!\n");
            return 1;
        }
        else if(check_alpha(argv[1]) > 0)
        {
            printf("Invalid key!\n");
            return 1;
        }

        string q = argv[1];
        string p = get_string("plaintext: ");
        printf("ciphertext: ");

        for(int i = 0; i < strlen(p); i++)
        {
            if(isupper(p[i]))
            {
                int j = (int)p[i] - 65;
                char a = toupper(q[j]);
                printf("%c", a);
            }
            else if(islower(p[i]))
            {
                int j = (int)p[i] - 97;
                char a = tolower(q[j]);
                printf("%c", a);
            }
            else if(isalpha(p[i]) == 0)
            {
                printf("%c", p[i]);
            }
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    printf("\n");
}

int only_once(string s)
{
    int count = 0;

    for (int i = 0; i < strlen(s) - 1; i++)
    {
        for(int j = i + 1; j < strlen(s); j++)
        {
            if(s[i] == s[j])
            {
                count += 1;
            }
        }

    }
    return count;
}

int check_alpha(string s)
{
    int count = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == 0)
        {
            count += 1;
        }
    }
    return count;
}