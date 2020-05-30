#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("Usage: ./substitution key");
        return 1;
    }

    else if(strlen(argv[1]) != 26) {
        printf("Key must contain 26 characters.");
        return 1;
    }

    string key = argv[1];

    int arr[26] = {0};

    for(int i = 0, n = strlen(key); i < n; i++) {
        if(isalpha(key[i]) == 0) {
            printf("Invalid keyword\n");
            return 1;
        }
        key[i] = toupper(key[i]);
    }

    for(int i = 0, n = strlen(key); i < n; i++) {
        if(arr[(int)(key[i]) % 65]) {
            printf("Invalid keyword\n");
            return 1;
        }
        arr[(int)key[i] % 65] = 1;
    }

    string ptext = get_string("plaintext: ");

    printf("ciphertext: ");

    for(int i = 0; i < strlen(ptext); i++)
        if(islower(ptext[i]))
            printf("%c", tolower(key[ptext[i] % 97]));
        else if(isupper(ptext[i]))
            printf("%c", key[ptext[i] % 65]);
        else
            printf("%c", ptext[i]);

    printf("\n");
    return 0;
}

