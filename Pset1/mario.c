#include <stdio.h>
#include <cs50.h>

int main (void)
{
    //Prompt for height
    int x;
    do
    {
        x = get_int("height: ");
    }
    //Remain prompting for height if it is < 1 and > 8
    while (x < 1 || x > 8);
    //Make rows
    for (int y = 0; y < x; y++)
    {
        //Make spaces within the for loop (rows)
        for (int z = 0; z < x - y - 1; z++)
        {
            printf(" ");
        }
        //Make # within the for loop (rows)
        for (int c = 0; c <= y; c++)
        {
            printf("#");
        }
        printf ("\n");
    }
}