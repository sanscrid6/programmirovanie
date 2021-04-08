#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"


int main()
{
    int length = 0, sum = 0, i = 0, check;
    struct Node* root = NULL;
    inputHandler(&root);
    if(root == NULL) printf("Tree is empty\n");
    else sumOfLongestBranch(&root, 0, &length, &sum);
    printf("Max length of branch is %i\nSum is %i", length, sum);
    freeTree(root);
    return 0;
}
