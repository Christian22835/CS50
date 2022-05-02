#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

string encrypt(string plaintext, int k);
//Check that program was run with one command-line argument
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Iterate over characters of the key and print error if any are non-digits
    int char_of_key;
    for (char_of_key = 0; char_of_key < strlen(argv[1]); char_of_key++)
    {
        if (isalpha(argv[1][char_of_key]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);
    //Check if key is a negative digit, if so print error
    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Continue and accept key
    else
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: %s\n", encrypt(plaintext, k));
        return 0;
    }
}

string encrypt(string plaintext, int k)
{
    string ciphertext = plaintext;
    for (int char_plain = 0; char_plain < strlen(plaintext); char_plain++)
    {
        //If uppercase preserve case after adding conv
        if (isupper(plaintext[char_plain]))
        {
            ciphertext[char_plain] = (((plaintext[char_plain] + k) - 65) % 26) + 65;
        }
        //If it is lowercase preserve case after adding conv
        else if (islower(plaintext[char_plain]))
        {
            ciphertext[char_plain] = (((plaintext[char_plain] + k) - 97) % 26) + 97;
        }
        //Anything else remains as is, doesn't require adding the key
        else
        {
            ciphertext[char_plain] = plaintext[char_plain];
        }
    }
    return ciphertext;
}