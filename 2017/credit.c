#include <math.h>
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Credit card number: ");
    long long int credit = get_long_long();

    long long int credit1 = credit;
    int dig = 0;
    while(credit != 0) // counts number of digits
    {
        credit /= 10;
        dig++;

    }

    credit = credit1;
    int sum0 = 0, sum1 = 0;
    credit /= 10;
    for(int i = 0; i < dig / 2; i++) // finds the sum of second-to-last digit times 2 thingy
    {
        sum1 = (credit % 10) * 2;
        if(sum1 / 10 == 0) {
            sum0 += sum1;
        }
        else {
            for(int j = 0; j < 2; j++) {
                sum0 += sum1 % 10; // sum 0 is your final value from this loop for the checksum
                sum1 /= 10;
            }
        }
//        printf("%lli | %d\n", credit, sum0);
        credit /= 100;
    }

    credit = credit1;
    int sum2 = 0;
    for(int i = 0; i <= dig / 2; i++) // adds the remaining numbers
    {
        sum2 += credit % 10; // sum 2 is your final value from this loop for the checksum
        credit /= 100;
//        printf("%lli | %d\n", credit, sum2);
    }

    int checksum = sum0 + sum2;
    if(checksum % 10 == 0) { // checks if the checksum modulus 10 is 0
        credit = credit1;
        if(dig == 16) {
            if(credit / 1000000000000000 == 4)
                printf("VISA\n");
            else if(credit / 100000000000000 >= 51 && credit / 100000000000000 <= 55)
                printf("MASTERCARD\n");
            else
                printf("INVALID\n");
        }

        else if(dig == 13) {
            if(credit / 1000000000000 == 4)
                printf("VISA\n");
            else
                printf("INVALID\n");
        }

        else if(dig == 15) {
            if(credit / 10000000000000 == 34 || credit / 10000000000000 == 37)
                printf("AMEX\n");
            else
                printf("INVALID\n");
        }
    }
    else
            printf("INVALID\n");
}
