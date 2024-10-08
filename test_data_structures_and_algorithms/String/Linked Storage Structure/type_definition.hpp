#ifndef __TYPE__
#define __TYPE__
#include <stdlib.h>
#include <string.h>
//#include <errno.h>
#include<iostream>
#define CHRUNKSIZE 80
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//串的链式存储
typedef struct
{
    char* ch[CHRUNKSIZE];//每个块链中数据域的大小
    Chunk* next;
}Chunk;

typedef struct
{
    Chunk* Head, Tail;//串的头指针尾指针
    int curlen;//串的当前长度--个人感觉不需要
}LString;


#endif