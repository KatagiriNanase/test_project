#ifndef __TYPE__
#define __TYPE__
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define _INIT_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status; // 定义函数的返回值
typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
} Sqlist;

void menu();

//线性表展示
void ShowList(Sqlist*);
// 线性表的初始化
Status InitList_Sq(Sqlist *);

// 销毁线性表
int DestroyList(Sqlist *);

// 清空线性表
int ClearList(Sqlist *);

// 获取线性表长度
int GetLength(Sqlist *);

// 判断线性表是否为零
int IsEmpty(Sqlist *L);

// 获取线性表元素
int GetElem(Sqlist *L, int i, ElemType e);

// 定位元素位置
int LocateElem(Sqlist *L, ElemType e);

// 插入元素
int InsertList(Sqlist *L, int i, ElemType e);

// 删除元素
int DeleteList(Sqlist *, int);
#endif
