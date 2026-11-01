#include <stdio.h>
#include <stdbool.h>
#include "LinkList.h"
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    // Set the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif
    LinkList *head = initList();
    insertHead(head, 10);
    insertHead(head, 20);
    insertHead(head, 30);
    insertTail(head, 50);
    insertMid(head, 2, 34);
    printf("链表的长度是: %d\n", getListLength(head));
    printList(head);

    bool flag = removeNode(head, 1);
    if (flag)
    {
        printf("删除成功\n");
    }
    else
    {
        printf("删除失败\n");
    }
    printf("链表的长度是: %d\n", getListLength(head));
    printList(head);

    deleteList(head);
    return 0;
}