#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "LinkList.h"

LinkList *initList()
{
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    head->data = -1;
    head->next = NULL;
    return head;
}

bool insertTail(LinkList *list, int data)
{
    LinkList *new_node = (LinkList *)malloc(sizeof(LinkList));
    LinkList *temp = list;
    while (temp->next)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->data = data;
    return true;
}

bool insertHead(LinkList *head, int data)
{
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->next = head->next;
    head->next = p;
    p->data = data;
    return true;
}

void printList(LinkList *head)
{
    LinkList *p = head->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

bool insertMid(LinkList *head, int pos, int data)
{
    int num = 1;
    LinkList *to_move = head;
    LinkList *new_node = (LinkList *)malloc(sizeof(LinkList));
    while (num < pos && to_move)
    {
        to_move = to_move->next;
        num++;
    }
    if (to_move == NULL)
        return false;
    else
    {
        new_node->next = to_move->next;
        new_node->data = data;
        to_move->next = new_node;
    }
    return true;
}

void deleteList(LinkList *head)
{
    LinkList *to_move = head->next;
    LinkList *to_delete = head;
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

bool removeNode(LinkList *head, int pos)
{
    LinkList *before_data = head;
    int num = 1;
    LinkList *to_move = head->next;
    while (to_move)
    {
        if (num == pos)
            break;
        before_data = to_move;
        to_move = to_move->next;
        num++;
    }
    if (to_move)
    {
        before_data->next = to_move->next;
        free(to_move);
        to_move=NULL;
    }
    else
    {
        return false;
    }
}

int getListLength(LinkList *head)
{
    LinkList *p = head->next;
    int num = 0;
    while (p)
    {
        p = p->next;
        num++;
    }
    return num;
}
