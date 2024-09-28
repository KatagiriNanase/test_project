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
    #ifndef __ELEMTYPE__
    #define __ELEMTYPE__
    typedef int ElemType;

    typedef struct Lnode
    {
        ElemType data;
        struct Lnode* next;
    } Lnode, * Linklist;
    #endif
// 初始化链表
int InitList_L(Linklist& L);

//判断链表是否为空
int IsEmpty(Linklist& L);

//销毁链表
int DestroyList(Linklist& L);

//清空链表
int ClearList(Linklist& L);

//获取链表长度
int Getlength(Linklist& L);

//获取指定下标数据
int GetElem_s(Linklist L, int i, ElemType e);

//按值查找--返回地址
Lnode* LocateElem_pointer(Linklist L, ElemType e);

//按值查找--返回位置
int LocateElem_subscribe(Linklist L, ElemType e);

//插入元素
int InsertElem(Linklist& L, int i, ElemType e);

//删除元素，保留被删除元素的数据域
int DeleteElem(Linklist& L, int i, ElemType& e);

//创建链表--头插法
void CreateList_Head(Linklist& L, int n);

//创建链表--尾插法
void CreateList_Rear(Linklist& L, int n);

//应用--线性表的合并
void UnionList(Linklist& La, Linklist& Lb);

//应用--有序表的合并--链式存储
void MergeLinklist(Linklist La, Linklist Lb, Linklist& Lc);

#endif