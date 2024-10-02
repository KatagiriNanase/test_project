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
typedef int SElemType;

//链栈
typedef struct StackNode
{
    SElemType data;//数据域
    StackNode* next;//
}StackNode, * LinkStack;

//链栈初始化
int InitStack(LinkStack& S);

//判断链栈是否为空
int IsEmpty(LinkStack S);

//链栈入栈
int Push(LinkStack& S, SElemType E);

//链栈出栈
int Pop(LinkStack& S, SElemType& E);

//获取栈顶元素
SElemType GetTop(LinkStack S);
#endif