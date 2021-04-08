#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"



void inputHandler(struct Node** root)
{
    int data = 3, result, i = 0, check = 0 ;
    char buff[50];
    while(1)
    {
        check = 0;
        printf("Enter number\n");
        fgets(buff, 50, stdin);
        for(i = 0; i<strlen(buff); i++)
        {
            if(buff[i] == '.' || buff[i] == ',') check = 2;
        }
        check += sscanf(buff, "%d", &data);
        if(check == 1 && data != 0) addNode(root, data);
        else if(check != 1) printf("Incorrect input\n");
        else if(check == 1 && data == 0) break;
    }
}

int addNode(struct Node** root, int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(!node)
    {
        return 1;
    }
    node->left = NULL;
    node->parent = NULL;
    node->right = NULL;
    node->data = data;
    if(!(*root))
    {
        *root = node;
    }
    else
    {
        struct Node* temp = *root;
        while(temp)
        {
            if (data < temp->data)
            {
                if(!temp->left)
                {
                    temp->left = node;
                    node->parent = temp;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (data > temp->data)
            {
                if(!temp->right)
                {
                    temp->right = node;
                    node->parent = temp;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                printf("%i already exists in tree\n", data);
                break;
            }
        }
    }
    return 0;
}

int sumFromCurrent(struct Node** current)
{
    int sum = 0;
    struct Node* tmp = *current;
    while(tmp)
    {
        sum+=tmp->data;
        tmp = tmp->parent;
    }
    return sum;
}

int lengthOfLeft(struct Node** current, int start, int* sum)
{
    struct Node* node;
    int length;
    *sum = sumFromCurrent(current);
    length = start;
    node = *current;
    while(node)
    {
        /*printf("left start(%i):%i\n", start, node->data);*/
        node = node->left;
        if(node) *sum+=node->data;
        length++;
    }
    return length;
}

int lengthOfRight(struct Node** current, int start, int* sum)
{
    struct Node* node;
    int length;
    *sum = sumFromCurrent(current);
    length = start;
    node = *current;
    while(node)
    {
        /*printf("right start(%i):%i\n", start, node->data);*/
        node = node->right;
        if(node) *sum+=node->data;
        length++;
    }
    return length;
}

void sumOfLongestBranch(struct Node** current, int start, int* length, int* sum)
{

    int left = 0;
    int right = 0;
    int sumL = 0, sumR = 0;
    if(current!=NULL)
    {
        left = lengthOfLeft(current, start, &sumL);
        right = lengthOfRight(current, start, &sumR);
        start++;
        if((*current)->left) sumOfLongestBranch(&((*current)->left), start, length, sum);
        if((*current)->right) sumOfLongestBranch(&((*current)->right), start, length, sum);
    }
    if(left>*length)
    {
        *length = left;
        *sum = sumL;
    }
    if(right>*length)
    {
        *length = right;
        *sum = sumR;
    }
}

void freeTree(struct Node* root)
{
    if(root!=NULL)
    {
        struct Node* left = root->left;
        struct Node* right = root->right;
        freeTree(left);
        freeTree(right);
        free(root);
    }
}
