#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "funcs.h"


void test()
{
    int i = 0;
    struct Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL, *tail3 = NULL;
    assert(push_back(&head1, &tail1, 1) == 0);
    assert(push_back(&head1, &tail1, 3) == 0);
    assert(push_back(&head1, &tail1, 5) == 0);
    assert(push_back(&head2, &tail2, 2) == 0);
    assert(push_back(&head2, &tail2, 3) == 0);
    assert(push_back(&head2, &tail2, 4) == 0);
    delElements(&head1, &head2, &head3, &tail3);
    for(i = 1 ; i<=5; i++)
    {
        assert(head3->value == i );
        head3 = head3->next;
    }
    assert(isEqual(1,2) == 0);
    assert(isEqual(1,1) == 1);
    assert(countSize(&head1) == 3);
    freeList(&head1);
    freeList(&head2);
    freeList(&head3);
}

int main()
{
    test();
    printf("Tests passed");
    return 0;
}
