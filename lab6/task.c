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
            return 1;
        }
    }
    /*addNode(&root ,7);
    addNode(&root, 3);
    addNode(&root, 1);
    addNode(&root, 9);
    addNode(&root, 21);
    addNode(&root, 4);
    addNode(&root, 5);
    addNode(&root, 6);
    addNode(&root, 20);
    addNode(&root, 19);
    addNode(&root, 18);
    addNode(&root, 17);
    addNode(&root, 16);*/
    sumOfLongestBranch(&root, 0, &length, &sum);
    printf("Max length of branch is %i\nSum is %i", length, sum);
    freeTree(root);
    return 0;
}
