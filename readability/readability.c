#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text1);
int count_words(string text1);
int count_sentences(string text1);

int main(void)
{
    string text = get_string("Text: ");
    int letters, words, sentences;
    float index, L, S;
    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);


    L = (float) letters / (float) words * 100;
    S = (float) sentences / (float) words * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}

int count_letters(string text1)
{
    int letters = 0;




    for (int i = 0; i < strlen(text1); i++)
    {
        if (isalpha(text1[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text1)
{
    int words = 0;




    for (int i = 0; i < strlen(text1); i++)
    {
        if (text1[i] == ' ')
        {
            words ++;
        }
    }
    if (strlen(text1) > 0)
    {
        words++;
    }

    return words;
}

int count_sentences(string text1)
{
    int sentences = 0;




    for (int i = 0; i < strlen(text1); i++)
    {
        if (text1[i] == '.' || text1[i] == '!' || text1[i] == '?')
        {
            sentences ++;

        }
    }

    return sentences;

}