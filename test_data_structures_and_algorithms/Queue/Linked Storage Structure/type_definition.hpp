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
typedef struct//链队节点和头指针定义
{
    QElemType data;
    Qnode* next;

}Qnode, * QueuePtr;

typedef struct//链队头尾指针定义
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

//链队初始化
int InitQueue(LinkQueue& Q);

//销毁链队
int DestroyQueue(LinkQueue& Q);

//入队
int EnQueue(LinkQueue& Q, QElemType E);

//出队
int DeQueue(LinkQueue& Q, QElemType& E);

//获取队头元素
int GetHead(LinkQueue Q,QElemType &E);
#endif
