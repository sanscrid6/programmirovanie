#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"



void push_back(struct Node** head, struct Node** tail, T data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = data;
    node->next = NULL;
    node->prev = NULL;
    if(!*head)
    {
        *head = node;
        *tail = node;
    }
    else
    {
        (*tail)->next = node;
        (*tail)->prev = *tail;
        (*tail) = node;
    }
}

int isEqual(T a, T b)
{
    if(a == b) return 1;
    return 0;
}

int countSize(struct Node** head)
{
    int size  = 0;
    struct Node* node = *head;
    while(node)
    {
        node = node->next;
        size++;
    }
    return size;
}

void print(struct Node** head)
{
    struct Node* node = *head;
    while(node)
    {
        printf("%i\t", node->value);
        node = node->next;
    }
}

void sort(struct Node** head)
{
    int size  = countSize(head), i = 0, j = 1;
    struct Node* node = *head;
    T* arr = (T*)malloc(sizeof(T) * size);
    node = *head;
    while(node)
    {
        arr[i] = node->value;
        node = node->next;
        i++;
    }
    node = *head;
    while(j>0)
    {
        j = 0;
        for(i = 0; i<size-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                T temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                j++;
            }
        }
    }
    i = 0;
    while(node)
    {
        node->value = arr[i];
        node = node->next;
        i++;
    }
    free(arr);
}


void delElements(struct Node** head1, struct Node** head2,struct Node** newHead,struct Node** newTail)
{
    struct Node* node1 = *head1;
    struct Node* node2 = *head2;
    int count = 0;
    while(node1 || node2)
    {

        if(!node1)
        {
            if (count > 0 && (*newTail)->value != node2->value)
            {
                push_back(newHead, newTail, node2->value);
            }
            else if(count == 0)
            {
                push_back(newHead, newTail, node2->value);
            }
            node2 = node2->next;
        }
        else if(!node2)
        {
            if (count > 0 && (*newTail)->value != node1->value)
            {
                push_back(newHead, newTail, node1->value);
            }
            else if(count == 0)
            {
                push_back(newHead, newTail, node1->value);
            }
            node1 = node1->next;
        }
        if(node1 && node2)
        {
            if(isEqual(node1->value, node2->value))
            {
                if (count > 0 && (*newTail)->value != node2->value)
                {
                    push_back(newHead, newTail, node2->value);
                }
                else if(count == 0)
                {
                    push_back(newHead, newTail, node2->value);
                }
                node1 = node1->next;
                node2 = node2->next;
            }
            else
            {
                if(node1->value > node2->value) {
                    if (count > 0 && (*newTail)->value != node2->value)
                    {
                        push_back(newHead, newTail, node2->value);
                    }
                    else if(count == 0)
                    {
                        push_back(newHead, newTail, node2->value);
                    }
                    node2 = node2->next;
                }
                else
                {
                    if (count > 0 && (*newTail)->value != node1->value)
                    {
                        push_back(newHead, newTail, node1->value);
                    }
                    else if(count == 0)
                    {
                        push_back(newHead, newTail, node1->value);
                    }
                    node1 = node1->next;
                }
            }
        }
        count++;
    }
}

void freeList(struct Node** head)
{
    struct Node* node = *head;
    while(node)
    {
        struct Node* n = node->next;
        free(node);
        node = n;
    }
}