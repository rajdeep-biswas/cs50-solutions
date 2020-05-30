#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("invalid input\n");
        return 1;
    }
    
    string key = argv[1];
    
    for(int i = 0, n = strlen(key); i < n; i++)
		if(key[i] >= 'A' && key[i] <= 'Z')
			key[i] += 32;
        else if(key[i] >= 'a' && key[i] <= 'z'){}
        else
            return 1;
    
    string arr = get_string("plaintext: ");
    
    printf("ciphertext: ");
    for(int i = 0, n = strlen(arr), keySize = strlen(key), j = 0; i < n; i++)
		if(arr[i] >= 'a' && arr[i] <= 'z')
			printf("%c", 'a' + (arr[i] - 'a' + (key[(j++ % keySize)] - 'a')) % 26);
		else if(arr[i] >= 'A' && arr[i] <= 'Z')
			printf("%c", 'A' + (arr[i] - 'A' + (key[(j++ % keySize)] - 'a')) % 26);
		else
			printf("%c", arr[i]);

	printf("\n");
    
}

