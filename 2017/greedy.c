#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int check = 0;
    float ch;
    printf("O hai! ");
    do
    {
        printf("How much change is owed?\n");
        ch = get_float();
            if(ch >= 0)
                check++;
    } while(check == 0);

//    printf("%f\n", ch);
    ch *= 100;
    ch = round(ch);
    int counter = 0;
//    printf("%f\n", ch);
    while(ch > 0)
    {
        if(ch - 25 >= 0)
        {
            ch -= 25;
            counter++;
        }
        else if(ch - 10 >= 0)
        {
            ch -= 10;
            counter++;
        }
        else if(ch - 5 >= 0)
        {
            ch -= 5;
            counter++;
        }
        else if(ch - 1 >= 0)
        {
            ch -= 1;
            counter++;
        }
//        printf("%f\n", ch);
    }

    printf("%i\n", counter);
}
