#include <stdlib.h>
#include <stdio.h>
#include "DoubleList.h"

DoubleList *initList()
{
    DoubleList *head = (DoubleList *)malloc(sizeof(DoubleList));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

bool insertHead(DoubleList*head,int data)
{
    DoubleList*new_node=(DoubleList*)malloc(sizeof(DoubleList));
    if(head->next)
    {
        new_node->data=data;
        new_node->next=head->next;
        head->next->prev=new_node;
        new_node->prev=head;
        head->next=new_node;
    }
    else
    {
        new_node->data=data;
        new_node->next=head->next;
        new_node->prev=head;
        head->next=new_node;
    }
    return true;
}

void printList(DoubleList*head)
{
    DoubleList*to_print=head->next;
    while(to_print)
    {
        printf("%d ",to_print->data);
        to_print=to_print->next;
    }
    putchar('\n');
}

void freeList(DoubleList *head)
{
    DoubleList *to_move = head->next;
    DoubleList *to_delete = head;
    free(to_delete);
    to_delete = NULL;
    while (to_move)
    {
        to_delete = to_move;
        to_move = to_move->next;
        free(to_delete);
        to_delete = NULL;
    }
}

