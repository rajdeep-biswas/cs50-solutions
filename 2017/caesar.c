#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    int key = atoi(argv[1]);
    if(key < 0)
    {
        printf("Key should be a non-negative integer\n");
        return 1;
    }

    printf("plaintext: ");
    string ptext = get_string();

    printf("ciphertext: ");
    for(int i = 0, n = strlen(ptext); i < n; i++) {
        if(isalpha(ptext[i]) != 0)
        {
            if(isupper(ptext[i]) != 0)
            {
                int text = ptext[i] - 'A';
                int dig = (text + key) % 26;
                printf("%c", 'A' + dig);
            }
            if(islower(ptext[i]) != 0)
            {
                int text = ptext[i] - 'a';
                int dig = (text + key) % 26;
                printf("%c", 'a' + dig);
            }
        }
        else
            printf("%c", ptext[i]);
    }

    printf("\n");
    return 0;
}
