#ifndef __TYPE__
#define __TYPE__
#include <stdlib.h>
#include <string.h>
//#include <errno.h>
#include <iostream>
#define _INIT_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef char Status; // 定义函数的返回值
typedef int ElemType;

typedef struct Lnode//双向链表的类型定义 
{
    ElemType data;
    struct Lnode* prior, * next;
} DuLnode, * DuLinklist;
/*
同理，可以实现双向循环链表
*/

//插入元素
int InsertElem(DuLinklist& L, int i, ElemType e);

//定位节点
DuLinklist LocateElem_pointer(DuLinklist& L, int i);

//删除元素
int DeleteElem(DuLinklist& L, int i,ElemType &e);

#endif