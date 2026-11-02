#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"
#include <string.h>

SeqStack *initSeqStack()
{
    SeqStack *s = (SeqStack *)malloc(sizeof(SeqStack));
    s->data = (int *)malloc(sizeof(int) * MAX_SIZE);
    memset(s->data, 0, sizeof(s->data));
    s->top = -1;
    return s;
}

bool push(SeqStack *s, int data)
{
    s->top++;
    if (s->top >= MAX_SIZE)
    {
        s->top--;
        return false;
    }
    s->data[s->top] = data;
    return true;
}

bool pop(SeqStack *s, int *e)
{
    if (s->top == -1)
    {
        printf("The stack is empty\n");
        return false;
    }
    *e = s->data[s->top];
    s->top--;
    return true;
}

bool getTop(SeqStack *s, int *e)
{
    if (s->top == -1)
    {
        printf("The Stack is empty\n");
        return false;
    }
    *e = s->data[s->top];
    return true;
}

bool freeSeqStack(SeqStack *s)
{
    free(s->data);
    free(s);
    return true;
}
