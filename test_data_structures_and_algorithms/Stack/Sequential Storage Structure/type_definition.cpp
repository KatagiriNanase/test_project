#include "type_definition.hpp"


int InitSqStack(SqStack& S)
{
    S.base = new SElemType[_INIT_SIZE];//new一块新数组给base指针
    if (!S.base)
        exit(OVERFLOW);//分配失败直接将程序退出
    S.top = S.base;//初始为空，指向数组下标为零处
    S.stacksize = _INIT_SIZE;

}

int IsEmpty(SqStack S)
{
    if (S.base == S.top)//两个相等为空
        return TRUE;
    else
        return FALSE;
}

int GetLength(SqStack S)
{
    return S.top - S.base;
}

int ClearStack(SqStack& S)
{
    if (S.base)//判断栈是否存在
    {
        S.top = S.base;
        return TRUE;
    }
    else
        return ERROR;
}

int DestroyStack(SqStack& S)
{
    if (S.base)
    {
        delete S.base;
        S.stacksize = 0;
        S.base = S.top = NULL;
    }
    return TRUE;

}

int Push(SqStack& S, SElemType E)
{
    if (S.top - S.base == S.stacksize)
        return OVERFLOW;
    else
    {
        *S.top++ = E;
        return OK;
    }
}

int Pop(SqStack& S, SElemType& E)
{
    if (S.top == S.base)
        return ERROR;
    else
    {
        E = *(--S.top);
        return OK;
    }
}

SElemType GetTop(SqStack S)
{
    if (S.top != S.base)
        return *S.top;
}