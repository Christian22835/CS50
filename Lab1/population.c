#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int x, y, a, b, n;
    do
    {
        x = get_int("start size: ");
    }
    while (x < 9);
    // TODO: Prompt for end size
    do
    {
        y = get_int("end size: ");
    }
    while (y < x);
    // TODO: Calculate number of years until we reach threshold
    for (n = 0; x < y; n++)
    {
        a = x/3;
        b = x/4;
        x = x + a - b;
    }
    // TODO: Print number of years
    printf("Years: %i", n);
}