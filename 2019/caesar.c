#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("invalid input\n");
        return 1;
    }
    
    int key = atoi(argv[1]);
    string arr = get_string("plaintext: ");
    
    printf("ciphertext: ");
    for(int i = 0, n = strlen(arr); i < n; i++) 
		if(arr[i] >= 'a' && arr[i] <= 'z')
			printf("%c", 'a' + ((arr[i] - 'a' + key) % 26));
		else if(arr[i] >= 'A' && arr[i] <= 'Z')
			printf("%c", 'A' + ((arr[i] - 'A' + key) % 26));
		else
			printf("%c", arr[i]);

	printf("\n");
    
}
