#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H
#include <stdbool.h>
typedef struct node
{
    int data;
    struct node *prev, *next;
} DoubleList;

DoubleList *initList();

bool insertHead(DoubleList *head, int data);

void printList(DoubleList *head);

void freeList(DoubleList *head);

#endif