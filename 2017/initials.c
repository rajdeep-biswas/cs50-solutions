#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
    string A = get_string();

    if(toupper(A[0]) >= 'A' && toupper(A[0]) <= 'Z') // provided the index location 0 is an alphabet
        printf("%c", toupper(A[0]));

    for(int i = 1, n = strlen(A); i < n; i++) { // checks if an alphabet is followed by (any number of) space(s)
        if(A[i] == ' ' && isalpha(A[i + 1]) != 0)
            printf("%c", toupper(A[i + 1]));
    }
    printf("\n");

    return 0;
}
