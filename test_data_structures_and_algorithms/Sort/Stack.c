#include "Stack.h"


//初始化
void StackInit(Stack* pst)
{
    assert(pst);

    pst->_a = (STDataType*)malloc(sizeof(STDataType) * 4);
    pst->_capacity = 4;
    pst->_top = 0;
}
//销毁
void StackDestroy(Stack* pst)
{
    assert(pst);

    free(pst->_a);
    pst->_a = NULL;
    pst->_top = pst->_capacity = 0;

}
//压栈
void Stackpush(Stack* pst, STDataType x)
{
    //空间扩容
    if (pst->_top == pst->_capacity)
    {
        pst->_capacity *= 2;
        STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->_capacity);

        if (!tmp)
        {
            printf("内存不足\n");
            exit(-1);
        }

        else
        {
            pst->_a = tmp;
            tmp = NULL;
        }

    }

    pst->_a[pst->_top] = x;
    ++pst->_top;
}
//出栈
void  StackPop(Stack* pst)
{
    assert(pst);
    assert(pst->_top);

    --pst->_top;
}

int StackSize(Stack* pst)
{
    assert(pst);

    return pst->_top;
}

int StackIsEmpty(Stack* pst)
{
    assert(pst);

    return pst->_top == 0 ? 1 : 0;
    //return !pst->_top;
}

STDataType StackTop(Stack* pst)
{
    assert(pst);
    assert(pst->_top > 0);

    return pst->_a[pst->_top - 1];
}