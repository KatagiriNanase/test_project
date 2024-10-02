#include "type_definition.hpp"

int InitStack(LinkStack& S)
{
    S = NULL;//构造一个空栈
    return OK;
}

int IsEmpty(LinkStack S)
{
    if (!S)
        return TRUE;
    else
        return FALSE;
}

int Push(LinkStack& S, SElemType E)
{
    StackNode* p = new StackNode;//生成新节点
    p->data = E;
    p->next = S;//将节点插入栈顶
    S = p;//修改栈顶指针
    return OK;
}

int Pop(LinkStack& S, SElemType& E)
{
    if (!S)
        return ERROR;
    E = S->data;//拿出栈顶元素
    LinkStack p = S;
    S = S->next;//栈顶下移
    delete p;//释放原栈顶内存
    p = NULL;
    return OK;

}

SElemType GetTop(LinkStack S)
{
    if (S)
        return S->data;
}