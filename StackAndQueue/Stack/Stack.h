#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

#define MAX_SIZE 100
typedef struct
{
    int *data;
    int top;
} SeqStack;

SeqStack *initSeqStack();

bool push(SeqStack *s, int data);

bool pop(SeqStack *s, int *e);

bool getTop(SeqStack *s, int *e);

bool freeSeqStack(SeqStack *s);

#endif