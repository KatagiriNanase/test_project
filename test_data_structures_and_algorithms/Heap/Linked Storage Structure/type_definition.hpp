#ifndef __TYPE__
#define __TYPE__
#include <stdlib.h>
#include <string.h>
//#include <errno.h>
#include<iostream>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int BTElemType;
typedef BTElemType SqBiTree[MAXSIZE];//数组类型的定义方式

/*二叉树的顺序存储法适用于满二叉树和完全二叉树，对于非完全二叉树需要在数组中存放0才能不破坏原有节点直接的孩子和双亲关系
*/


#endif