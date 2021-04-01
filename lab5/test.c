#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "funcs.h"
#define T int

void test()
{
    struct Node* head = NULL;
    struct Node* tail = NULL;
    push_back(&head, &tail, 1);
    push_back(&head, &tail, 2);
    push_back(&head, &tail, 3);
    push_back(&head, &tail, 4);
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