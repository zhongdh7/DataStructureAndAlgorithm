#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#define MAXSIZE 100



typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;


typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;
bool isEmpty(Queue*);

Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

bool push(Queue *q, int data)
{
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;
    q->rear->next = new_node;
    q->rear = new_node;
    return true;
}

bool pop(Queue *q, int *e)
{
    if (isEmpty(q))
        return false;
    QueueNode *to_remove = q->front->next;
    *e = to_remove->data;
    q->front->next = to_remove->next;
    if (q->rear == to_remove)
    {
        q->rear = q->front;
    }
    free(to_remove);
    return true;
}

int getFront(Queue*q)
{
    if(isEmpty(q))
    {
        return -1;
    }
    else
    {
        return q->front->next->data;
    }
}

bool isEmpty(Queue *q)
{
    if (q->front == q->rear)
        return true;
    else
        return false;
}

int main()
{
#ifdef _WIN32
    // Set the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif
    Queue *q = initQueue();
    push(q,10);
    push(q,20);
    push(q,30);
    push(q,40);
    push(q,50);
    int e;
    while(!isEmpty(q))
    {
        pop(q,&e);
        printf("%d ",e);
    }
    putchar('\n');

    return 0;
}