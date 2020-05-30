#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <cs50.h>

int main(int argc, string argv[]) {
    string hash = argv[1];
    string salty = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    char key[6];
	char salt[] = {hash[0], hash[1], '\0'};
    
    for(int a1 = 0; a1 < 53; a1++)
		for(int a2 = 0; a2 < 53; a2++)
			for(int a3 = 0; a3 < 53; a3++)
				for(int a4 = 0; a4 < 53; a4++)
					for(int a5 = 0; a5 < 53; a5++) {
						key[0] = salty[a5];
						key[1] = salty[a4];
						key[2] = salty[a3];
						key[3] = salty[a2];
						key[4] = salty[a1];

						if(!strcmp(crypt(key, salt), hash)) {
							printf("%s\n", key);
							return 1;
						}
					}
}

