#include<stdio.h>
#include<stdlib.h>

typedef struct L_Node{
    int data;
    struct L_Node* next;
} LNode;

LNode* GetNewListNode(int d)
{
    LNode* node = (LNode*)malloc(sizeof(LNode));

    if(node == NULL)
    {
        return NULL;
    }

    node->data = d;
    node->next = NULL;
    return node;
}

void pushNodeToHead(LNode** headRef, int data)
{
    if (*headRef == NULL)
    {
        *headRef = GetNewListNode(data);
        return;
    }

    LNode* newNode = GetNewListNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(LNode** head)
{
    LNode* temp = *head;

    while(temp!=NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
}
/*Find the middle element of a Linked List*/

LNode* FindMiddle(LNode* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        return head;
    }

    LNode* temp = head;
    LNode* temp2 = head;

    while(temp2 != NULL && temp2->next != NULL)
    {
        temp2 = temp2->next->next;
        temp = temp->next;
    }

    return temp;
}


int main()
{
    LNode* list = NULL;
    pushNodeToHead(&list, 1);
    /*pushNodeToHead(&list, 2);
    pushNodeToHead(&list, 3);
    pushNodeToHead(&list, 4);
    pushNodeToHead(&list, 5);
    printList(&list);*/
    LNode* middle = FindMiddle(list);
    if (middle!=NULL)
    {
        printf("%d", middle->data);
    }

}
