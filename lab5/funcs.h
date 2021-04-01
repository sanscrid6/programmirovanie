#ifndef FUNCS_H
#define FUNCS_H
typedef int T;

struct Node{
    T value;
    struct Node* next;
    struct Node* prev;
};

void push_back(struct Node** head, struct Node** tail, T data);
int isEqual(T a, T b);
int countSize(struct Node** head);
void print(struct Node** head);
void sort(struct Node** head);
void delElements(struct Node** head1, struct Node** head2,struct Node** newHead,struct Node** newTail);
void freeList(struct Node** head);

#endif