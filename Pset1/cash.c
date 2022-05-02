#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Prompt for change owed stipulating only positive amounts while also supporting decimals
    float owed;
    do
    {
        owed = get_float("change owed: ");
    }
    while (owed < 0);
    //Convert dollar amount entirely to amount in change
    int cents = round(owed * 100);
    //Establish a variable and solve for the lowest amount of coins required to return the customers change by checking greatest valued denomination to the least valuable all while adding coins as permitted
    int coins = 0;

    while (cents >= 25)
    {
        cents = cents - 25;
        coins ++;
    }
    while (cents >= 10)
    {
        cents = cents - 10;
        coins ++;
    }
    while (cents >= 5)
    {
        cents = cents - 5;
        coins ++;
    }
    while (cents >= 1)
    {
        cents = cents - 1;
        coins ++;
    }
    //Print the amount of coins so that cashier can most efficiently disperse from greatest valued denomination to the least valuable using the least amount of coins
    printf("amount of coins: %i\n", coins);
}