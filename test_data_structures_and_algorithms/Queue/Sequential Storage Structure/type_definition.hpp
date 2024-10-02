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



#endif
