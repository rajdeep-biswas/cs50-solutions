#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    string key = argv[1];

    for(int i = 0, n = strlen(key); i < n; i++) {
        if(isalpha(key[i]) == 0)
        {
            printf("Invalid keyword\n");
            return 1;
        }
    }
    printf("plaintext: ");
    string ptext = get_string();

    printf("ciphertext: ");
    int i = 0, n = strlen(ptext);
    for(int j = 0; i < n; i++) {
        if(isalpha(ptext[i]) != 0)
        {
            char c = toupper(ptext[i]);
            char d = toupper(key[j++ % strlen(key)]);
            int p = c % 'A';
            int k = d % 'A';
            int foo = (p + k) % 26;
            char o = 'A' + foo;

            if(islower(ptext[i]) != 0)
                printf("%c", tolower(o));
            else
                printf("%c", o);
        }
        else
            printf("%c", ptext[i]);
    }

    printf("\n");
    return 0;
}
