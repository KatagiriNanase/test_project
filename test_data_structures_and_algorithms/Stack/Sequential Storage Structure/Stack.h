#pragma once
#include <assert.h>
#include <stdlib.h>
typedef int STDataType;

typedef struct Stack
{
    STDataType* _a;
    int _top;   //栈顶
    int _capacity;
}Stack;

//初始化
void StackInit(Stack* pst);
//销毁
void StackDestroy(Stack* pst);
//压栈
void Stackpush(Stack* pst, STDataType x);
//出栈
void  StackPop(Stack* pst);

int StackSize(Stack* pst);

int StackIsEmpty(Stack* pst);

STDataType StackTop(Stack* pst);