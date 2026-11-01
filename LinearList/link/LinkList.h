#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} LinkList;

// 初始化链表操作函数
LinkList *initList();

// 尾插法
bool insertTail(LinkList *list, int data);

// 头插法
bool insertHead(LinkList *head, int data);

// 展示所有的数据
void printList(LinkList *head);

// 在内部插入
bool insertMid(LinkList *head, int pos, int data);

// 删除一个节点
bool removeNode(LinkList *head, int pos);

// 获取链表长度
int getListLength(LinkList *head);

// 查找倒数第几个数据
int findLastData(LinkList *head, int last_pos);

// 删除链表
void deleteList(LinkList *head);

#endif