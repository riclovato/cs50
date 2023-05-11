#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string rotate(string text, int key);
bool only_digits(string key);

int main(int argc, string argv[])
{
    string ciphertext;
// make program run with just one command-line argument~
    if (argc != 2)
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }
//make sure every character in argv[1] is a digit
    if (only_digits(argv[1]) == 1)
    {
        return 1;
    }
// convert argv[1] from string to int
    int check = atoi(argv[1]);
//prompt user for plaintext
    string text = get_string("Plaintext: ");

// for each character in plaintext:

//rotate the character if it's a letter
    ciphertext = rotate(text, check);
    printf("Ciphertext: %s\n", ciphertext);
}


bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]) == 0)
        {
            return 1;
        }
    }
    return 0;

}

string rotate(string text, int key)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = text[i] - 65;
                text[i] = (text[i] + key) % 26;
                text[i] = text[i] + 65;
            }
            else
            {
                text[i] = text[i] - 97;
                text[i] = (text[i] + key) % 26;
                text[i] = text[i] + 97;
            }
        }
    }
    return text;
}