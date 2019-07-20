#include <stdio.h>
#include <math.h>
#include <cs50.h>

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

int main(void) {
    float dollars;
    int coins = 0;
    do
    {
        dollars = get_float("Change owed: ");
    } while (dollars < 0);
    
    int cents = round(dollars * 100);

    while (cents >= QUARTER)
    {
        coins++;
        cents -= QUARTER;
    }
    while (cents >= DIME)
    {
        coins++;
        cents -= DIME;
    }
    while (cents >= NICKEL)
    {
        coins++;
        cents -= NICKEL;
    }
    while (cents >= PENNY)
    {
        coins++;
        cents -= PENNY;
    }
    
    printf("%i\n", coins);
}
