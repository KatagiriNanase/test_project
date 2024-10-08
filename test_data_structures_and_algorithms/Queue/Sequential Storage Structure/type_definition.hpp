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

typedef int QElemType;
typedef struct
{
    QElemType* base;//数组地址
    int front;//头指针
    int rear;//尾指针

}SqQueue;//顺序队列

//初始化顺序循环队
int InitQueue(SqQueue& Q);

//获取长度
int GetLenth(SqQueue Q);

//入队
int EnQueue(SqQueue& Q, QElemType E);

//出队
int DeQueue(SqQueue& Q, QElemType& E);

//取对头元素
QElemType GetHead(SqQueue Q);
#endif
