#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "phonebook_hashfunction.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *hash_table[TABLE_SIZE];

void initialize()
{
    for(int i=0; i<TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    return ;
}

int TransHashKey(char *lastName,int size)
{
    if (!lastName) return 0;
    int  i, val;
    for ( i = 0, val = 0; *lastName != '\0'; i++, lastName++) {
        val +=val*i+*lastName;
    }
    return abs(val % size);
}

entry *findName(char lastName[], entry *pHead)
{
    entry *tmp_name;
    int index = TransHashKey(lastName, TABLE_SIZE);
    tmp_name = hash_table[index];
    while (tmp_name != NULL) {
        if (strcasecmp(lastName, tmp_name->lastName) == 0)
            return tmp_name;
        tmp_name = tmp_name->pNext;
    }

    return NULL;
}

entry *append(char lastName[], entry *e)
{
    int index = TransHashKey(lastName,TABLE_SIZE);
    entry *newEntry;
    entry *curEntry;
    // Append
    if(hash_table[index]) {
        newEntry = hash_table[index];
        while(newEntry) {
            curEntry = newEntry;
            newEntry = newEntry ->pNext;
        }
        newEntry = (entry *) malloc(sizeof(entry));
        strcpy(newEntry->lastName, lastName);
        curEntry->pNext = newEntry;
        newEntry->pNext = NULL;
        return newEntry;
    } else {
        newEntry = (entry *) malloc(sizeof(entry));
        strcpy(newEntry->lastName, lastName);
        newEntry->pNext = NULL;
        hash_table[index] = newEntry;
        return newEntry;
    }
    e->pNext = (entry *)malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}
