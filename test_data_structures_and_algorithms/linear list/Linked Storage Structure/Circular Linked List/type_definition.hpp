#ifndef __TYPE__
#define __TYPE__
#include <stdlib.h>
#include <string.h>
//#include <errno.h>
#include<iostream>
#define _INIT_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef char Status; // 定义函数的返回值
typedef int ElemType;

typedef struct Lnode
{
    ElemType data;
    struct Lnode* next;
} Lnode, * Linklist;

// 初始化链表
int InitList_L(Linklist& L);

//合并循环链表
Linklist ConnectList(Linklist Ta, Linklist Tb);
#endif

//判断链表是否为空
int IsEmpty(Linklist& L);

/*
其他操作与单链表的区别
1.判断指针到结尾的条件改为 L->next==L
2.循环链表我们一般操作的是它的尾指针，这样可以很容易让我们得到它的尾元素和首元素。

*/