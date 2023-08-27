//Implementation of Symbol table using Hash technique
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct Symbol 
{
    char *name;
    int value;  
    struct Symbol *next;
};

struct SymbolTable 
{
    struct Symbol *sptr[SIZE];
};

unsigned int hash(const char *str) 
{
    unsigned int hash = 0;
    while(*str) 
    {
        hash = (hash << 5) + *str++;
    }
    return hash % SIZE;
}

void insert(struct SymbolTable *table, const char *name, int value) 
{
    unsigned int index = hash(name);
    struct Symbol *entry = (struct Symbol *)malloc(sizeof(struct Symbol));
    if (!entry) 
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(entry->name ,name);
    entry->value = value;
    entry->next = table->sptr[index];
    table->sptr[index] = entry;
}

struct Symbol *search(struct SymbolTable *table, const char *name) 
{
    unsigned int index = hash(name);
    struct Symbol *entry = table->sptr[index];
    while (entry != NULL) 
    {
        if (strcmp(entry->name, name) == 0) 
        {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

int main() 
{
    struct SymbolTable symbol_table;
    for (int i = 0; i < SIZE; i++) 
    {
        symbol_table.sptr[i] = NULL;
    }

    insert(&symbol_table, "x", 42);
    insert(&symbol_table, "y", 23);

    struct Symbol *entry_x = search(&symbol_table, "x");
    if (entry_x) 
    {
        printf("Symbol: %s, Value: %d\n", entry_x->name, entry_x->value);
    } else 
    {
        printf("Symbol not found.\n");
    }

    for (int i = 0; i < SIZE; i++) 
    {
        struct Symbol *entry = symbol_table.sptr[i];
        while (entry) 
        {
            struct Symbol *next = entry->next;
            free(entry->name);
            free(entry);
            entry = next;
        }
    }
    return 0;
}
