#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    float f;
    
    do {
        f = get_float("Change owed: ");
    } while(f <= 0.0);
    
    int change = round(f * 100);
    
    int coins = 0;
    
    coins += change / 25;
    change %= 25;
    
    coins += change / 10;
    change %= 10;
    
    coins += change / 5;
    change %= 5;
    
    coins += change;
    
    printf("%d\n", coins);
}

