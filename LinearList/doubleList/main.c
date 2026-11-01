#include <stdio.h>
#include "DoubleList.h"
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    // Set the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif
    DoubleList*head=initList();
    insertHead(head,4);
    insertHead(head,2);
    insertHead(head,43);
    insertHead(head,5);
    printList(head);
    freeList(head);
    return 0;
}