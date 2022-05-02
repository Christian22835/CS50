#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string sample);
int count_words(string sample);
int count_sent(string sample);

int main(void)
{
    //Get text
    string sample = get_string("Text: ");
    float totalletters = count_letters(sample);
    float totalwords = count_words(sample);
    float totalsent = count_sent(sample);
    //Coleman-Liau index
    float l = totalletters / totalwords * 100;
    float s = totalsent / totalwords * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int gradelvl = round(index);
    //Print grade level w/ caviats
    if (gradelvl >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (gradelvl < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", gradelvl);
    }
}

int count_letters(string sample)
{
    int amtchar = 0;
    // Count characters
    for (int letterofsample = 0; letterofsample < strlen(sample); letterofsample++)
    {
        if (isalpha(sample[letterofsample]))
        {
            amtchar++;
        }
    }
    return amtchar;
}

int count_words(string sample)
{
    int amtwords = 1;
    // Count words
    for (int letterofsample = 0; letterofsample < strlen(sample); letterofsample++)
    {
        if (isspace(sample[letterofsample]))
        {
            amtwords++;
        }
    }
    return amtwords;
}

int count_sent(string sample)
{
    int amtsent = 0;
    // Count sentences
    for (int letterofsample = 0; letterofsample < strlen(sample); letterofsample++)
    {
        if ((sample)[letterofsample] == '.' || (sample)[letterofsample] == '!' || (sample)[letterofsample] == '?')
        {
            amtsent++;
        }
    }
    return amtsent;
}