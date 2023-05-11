// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 50000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int h = hash(word);

    node *nodebuffer = table[h];

    while (nodebuffer != NULL)
    {
        if (strcasecmp(word, nodebuffer->word) == 0)
        {
            return true;
        }
        nodebuffer = nodebuffer->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    unsigned long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum = sum + tolower(word[i]);
    }
    return sum % N;
}
int count = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // memory allocation

    // opens file and checks if sucessfully opens the file
    FILE *inputFile = fopen(dictionary, "r");
    if (inputFile == NULL)
    {
        return false;
    }
    char word_buffer[LENGTH + 1];
    while (fscanf(inputFile, "%s", word_buffer) != EOF)
    {
        node *nodeNew = malloc(sizeof(node));
        if (nodeNew == NULL)
        {
            return false;
        }
        strcpy(nodeNew->word, word_buffer);
        unsigned int index = hash(word_buffer);
        if (table[index] != NULL)
        {
            nodeNew->next = table[index];
            count++;
        }
        else
        {
            nodeNew->next = NULL;
        }
        table[index] = nodeNew;
        count++;
    }

    fclose(inputFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // done

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *nodebuffer = table[i];

        while (nodebuffer != NULL)
        {
            node *tmp = nodebuffer;

            nodebuffer = nodebuffer->next;

            free(tmp);
        }
        if (nodebuffer == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
