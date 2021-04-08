#ifndef FUNCS_H
#define FUNCS_H
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

int addNode(struct Node** root, int data);
int sumFromCurrent(struct Node** current);
int lengthOfLeft(struct Node** current, int start, int* sum);
int lengthOfRight(struct Node** current, int start, int* sum);
void sumOfLongestBranch(struct Node** current, int start, int* length, int* sum);
void freeTree(struct Node* root);
void inputHandler(struct Node** root);

#endif
