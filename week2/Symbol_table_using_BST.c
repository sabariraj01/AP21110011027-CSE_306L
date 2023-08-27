//BST implementation of Symbol table
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    char key[100];
    int value;
    char type[10];
    char token[15];

    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* curr, char* key, int value,char *type,char *token) 
{
    if (curr == NULL) 
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        strcpy(newNode->key, key);
        newNode->value = value;
        strcpy(newNode->type, type);
        strcpy(newNode->token,token);
        
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (strcmp(key, curr->key) < 0) 
    {
        curr->left = insert(curr->left, key, value,type,token);
    } 
    else if (strcmp(key, curr->key) > 0) 
    {
        curr->right = insert(curr->right, key, value,type,token);
    }
    return curr;
}

int search(struct Node* curr, char* key) 
{
    if (curr == NULL || strcmp(curr->key, key) == 0) 
    {
        return curr != NULL ? curr->value : -1;
    }
    if (strcmp(key, curr->key) < 0) 
    {
        return search(curr->left, key);
    }
    return search(curr->right, key);
}

int main() 
{
    struct Node* root = NULL;
    root = insert(root, "x", 8,"int","keyword");
    root = insert(root, "y", 27,"int","keyword");
    root = insert(root,"+",0,"operator","operator");
    printf("%d\n", search(root, "y"));
    printf("%d\n", search(root, "x"));
    return 0;
}
