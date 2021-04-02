#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "funcs.h"

void test()
{
    int sum = 0, length = 0;
    struct Node* root = NULL;
    assert(addNode(&root ,7) == 0);
    assert(addNode(&root, 3) == 0);
    assert(addNode(&root, 1) == 0);
    assert(addNode(&root, 9) == 0);
    assert(addNode(&root, 21) == 0);
    assert(addNode(&root, 22) == 0);
    assert(addNode(&root, 4) == 0);
    assert(addNode(&root, 5) == 0);
    assert(addNode(&root, 6) == 0);
    assert(sumFromCurrent(&(root->left->right->right)) == 19);
    assert(lengthOfLeft(&root, 0, &sum) == 3);
    assert(sum == 11);
    sum = 0;
    assert(lengthOfRight(&root, 0, &sum) == 4);
    assert(sum == 59);
    sum = 0;
    sumOfLongestBranch(&root,0,&length,&sum);
    assert(length == 5);
    assert(sum == 25);
    freeTree(root);

}

int main()
{
    test();
    printf("Tests passed");
    return 0;
}