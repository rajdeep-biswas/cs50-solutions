#include <stdio.h>
#include <cs50.h>

int main(void) {
    long card = get_long("Number: ");
    
    int carray[16], l = 0, valid  = 0, checksum = 0;
    
    while(card != 0) {
        carray[l] = card % 10;
        card /= 10;
        l++;
  	}
    
   	for(int i = 1; i < l; i += 2) {
   		if((carray[i] * 2) / 10 != 0)
   			checksum += (carray[i] * 2) % 10 + (carray[i] * 2) / 10;
   		else
   			checksum += carray[i] * 2;
   	}

   	for(int i = 0; i < l; i += 2)
   		checksum += carray[i];

   	if(checksum % 10 == 0) {
   		if(l == 16) {
			if(carray[l - 1] == 5 && (carray[l - 2] == 1 || carray[l - 2] == 2 || carray[l - 2] == 3 || carray[l - 2] == 4 || carray[l - 2] == 5))
				printf("MASTERCARD\n");
			else if(carray[l - 1] == 4)
				printf("VISA\n");
            else
				printf("INVALID\n");
		}
		else if(l == 15 && carray[l - 1] == 3 && (carray[l - 2] == 4 || carray[l - 2] == 7))
			printf("AMEX\n");
		else if(l == 13 && carray[l - 1] == 4)
			printf("VISA\n");
		else
			printf("INVALID\n");
   	}
   	else
   		printf("INVALID\n");
}

