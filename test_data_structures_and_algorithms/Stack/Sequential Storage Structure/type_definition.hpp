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
typedef struct SqStack
{
    SElemType* top;
    SElemType* base;//栈底指针不发生变化
    int stacksize;//栈可用最大容量
}SqStack;
//初始化空栈
int InitSqStack(SqStack& S);

//判断栈是否为空
int IsEmpty(SqStack);

//获取顺序栈长度
int GetLength(SqStack);

//清空顺序栈
int ClearStack(SqStack& S);

//销毁顺序栈
int DestroyStack(SqStack& S);

//顺序栈入栈
int Push(SqStack& S, SElemType E);

//顺序栈出栈
int Pop(SqStack& S, SElemType& E);

//取栈顶元素
SElemType GetTop(SqStack S);
#endif