// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

int count = 0;

// Represents a node in a trie
typedef struct node
{
    bool isWord;
    struct node *children[N];
}
node;

// Represents a trie
node *root;

unsigned int hash(const char c) {
    if(c == '\'')
        return 26;
    return c - 'a';
}

char unhash(unsigned int d) {
    if(d == 26)
        return '\'';
    return 'a' + d;
}

void showTrie(char word[]) {
    node *ptr = root;
    int i = 0;

    while(ptr != NULL) {
        printf("%c-", word[i]);
        ptr = ptr -> children[hash(word[i++])];
    }
}

node* newNode() {
    node *nu = malloc(sizeof(node));
    nu -> isWord = 0;
    for (int i = 0; i < N; i++)
    {
        nu->children[i] = 0;
    }
    return nu;
}

const char *dict = NULL;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    dict = dictionary;
    // Initialize trie
    root = newNode();

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        node *ptr = root;
        for(int i = 0, n = strlen(word); i < n; i++) {
            if(ptr -> children[hash(word[i])] == NULL)
                ptr -> children[hash(word[i])] = newNode();

            ptr = ptr -> children[hash(word[i])];
        }
        ptr -> isWord = true;
        count++;
//        showTrie(strcat(word, "'"));
//        printf("\n");
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *ptr = root;

    for(int i = 0, n = strlen(word); i < n; i++) {
        char lowered = tolower(word[i]);
        if(hash(lowered) <= 27)
            ptr = ptr -> children[hash(lowered)];
        else return false;

        if(ptr == NULL)
            return false;
    }

    return ptr -> isWord;
}

bool freeTrie(node* rut) {
    if(rut == NULL)
        return true;

    else
        for(int i = 0; i < N; i++)
            freeTrie(rut -> children[i]);

    free(rut);

    return true;
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    return freeTrie(root);
}

