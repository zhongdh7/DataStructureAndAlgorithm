#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Book.h"
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_SIZE 100

typedef struct SeqList
{
    int *data;
    int length;
} SeqList;

bool appendElem(SeqList *list, int elem)
{
    if (list->length >= MAX_SIZE)
        return false;
    else
        list->data[list->length] = elem;
    list->length++;
    return true;
}

SeqList *initList()
{
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));
    L->data = (int *)malloc(sizeof(int) * MAX_SIZE);
    L->length = 0;
    return L;
}

void printList(SeqList *list)
{
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

bool insertList(SeqList *list, int pos, int elem)
{
    if (pos < 0 || pos > list->length || list->length == MAX_SIZE)
    {
        return false;
    }
    for (int i = list->length; i > pos; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    list->data[pos] = elem;
    list->length++;
    return true;
}

bool removeElem(SeqList *list, int pos, int *deletData)
{
    if (pos < 0 || pos >= list->length)
    {
        return false;
    }
    *deletData = list->data[pos];
    for (int i = pos; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->data[list->length - 1] = 0;
    list->length--;

    return true;
}

int findElem(SeqList *list, int elem)
{
    if (list->length == 0)
    {
        printf("The list is empty\n");
        return -1;
    }
    for (int i = 0; i < list->length; i++)
    {
        if (list->data[i] == elem)
        {
            return i;
        }
    }
    printf("There is no such element\n");
    return -1;
}

void clearList(SeqList*list)
{
    free(list->data);
    free(list);
}

int main()
{
#ifdef _WIN32
    // Set the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif
    Book b1;
    strcpy(b1.ISBN, "978-3-16-148410-0");
    strcpy(b1.title, "C++ Programming");
    b1.price = 29.99;

    printf("ISBN: %s\n", b1.ISBN);
    printf("Title: %s\n", b1.title);
    printf("Price: %.2f\n", b1.price);

    SeqList* list = initList();

    printf("Length of the list: %d\n", list->length);

    if (appendElem(list, 1928))
    {
        printf("Element appended successfully.\n");
        printf("The element is: %d\n", list->data[list->length - 1]);
    }
    else
    {
        printf("Failed to append element.\n");
    }

    if (insertList(list, 0, 18))
    {
        printf("Element inserted successfully.\n");
        printList(list);
    }
    else
    {
        printf("Failed to insert element.\n");
    }
    int temp;
    insertList(list, 1, 90);
    insertList(list, 1, 89);
    insertList(list, 1, 76);
    printList(list);
    removeElem(list, 2, &temp);
    printList(list);
    printf("%d\n", temp);
    printf("%d\n", findElem(list, 1928));
    clearList(list);

    return 0;
}