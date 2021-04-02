#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"


int main() {
    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;
    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;
    struct Node* newHead = NULL;
    struct Node* newTail = NULL;
    int i = 0, check;
    srand(time(0));
    for(i = 0; i<10;i++)
    {
        check = push_back(&head2, &tail2, -30 + rand()%60);
        if(check == 1)
        {
            printf("Malloc error");
            return 1;
        }
        check = push_back(&head1, &tail1, -30 + rand()%60);
        if(check == 1)
        {
            printf("Malloc error");
            return 1;
        }
    }
    check = sort(&head1);
    if(check == 1)
    {
        printf("Malloc error");
        return 2;
    }
    print(&head1);
    printf("\n\n");
    check = sort(&head2);
    if(check == 1)
    {
        printf("Malloc error");
        return 2;
    }
    print(&head2);
    printf("\n\n");
    delElements(&head1,&head2, &newHead, &newTail);
    print(&newHead);
    freeList(&head1);
    freeList(&head2);
    freeList(&newHead);
    return 0;
}