#include<stdio.h>
#include<stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* GetNewStackNode()
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));

    if (node == NULL)
    {
        printf("Error allocating node!");
        exit(1);
    }

    return node;
}

void push(StackNode** top, StackNode* newNode)
{
    if (newNode == NULL)
    {
        printf("Trying to push empty node!!");
        exit(1);
    }

    if (*top == NULL)
    {
        *top = newNode;
        return;
    }

    newNode->next = *top;
    *top = newNode;
}

StackNode* pop(StackNode** top)
{
    StackNode* temp;
    if (*top == NULL)
    {
        printf("Nothing to pop! Stack is empty.");
        return NULL;
    }

    temp = *top;
    *top = temp->next;
    return temp;
}

void printStack(StackNode** top)
{
    StackNode* temp = *top;
    while (temp!= NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
}

/*
int main()
{
    StackNode* s = NULL;
    StackNode* node1 = GetNewNode();
    node1->data = 5;
    node1->next = NULL;
    push(&s, node1);

    StackNode* node2 = GetNewNode();
    node2->data = 10;
    node2->next = NULL;
    push(&s, node2);

    StackNode* node3 = GetNewNode();
    node3->data = 12;
    node3->next = NULL;
    push(&s, node3);

    StackNode* node4 = GetNewNode();
    node4->data = 1;
    node4->next = NULL;
    push(&s, node4);

    pop(&s);
    printStack(&s);
}*/
