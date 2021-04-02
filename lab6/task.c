#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"


int main()
{
    int length = 0, sum = 0, i = 0, check;
    unsigned int size;
    struct Node* root = NULL;
    srand(time(0));
    size = 10 + rand()%30;
    for(i = 0; i<size;i++)
    {
        check = addNode(&root, rand()%35);
        if(check == 1)
        {
            printf("Malloc error");
            return 1;
        }
    }
    sumOfLongestBranch(&root, 0, &length, &sum);
    printf("Max length of branch is %i\nSum is %i", length, sum);
    freeTree(root);
    return 0;
}
