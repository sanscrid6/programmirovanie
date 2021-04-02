#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "funcs.h"


void test()
{
    struct Node* head = NULL;
    struct Node* tail = NULL;
    assert(push_back(&head, &tail, 1) == 0);
    assert(push_back(&head, &tail, 2) == 0);
    assert(push_back(&head, &tail, 3) == 0);
    assert(push_back(&head, &tail, 4) == 0);
    assert(isEqual(1,2) == 0);
    assert(isEqual(1,1) == 1);
    assert(countSize(&head) == 4);
    freeList(&head);
}

int main()
{
    test();
    printf("Tests passed");
    return 0;
}