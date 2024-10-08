#ifndef __TYPE__
#define __TYPE__
#include <stdlib.h>
#include <string.h>
//#include <errno.h>
#include<iostream>
#define MAXLEN 255
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//串的顺序存储结构
typedef struct
{
    char ch[MAXLEN + 1];//存储串的一维数组
    int length;
}SString;

//查找子串位置--BF算法
int IndexStringBF(SString S, SString T, int pos);

//查找子串位置--KMP算法
int IndexStringKMP(SString S, SString T, int pos);

//获取next数组
void GetNext(SString T, int(& next)[]);
#endif