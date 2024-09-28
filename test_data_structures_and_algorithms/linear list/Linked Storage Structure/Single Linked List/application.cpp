//多项式的初始化和相加
#include "type_definition.hpp"
#define __ELEMTYPE__

typedef struct Elemtype
{
    float coef;//系数
    float expn;//指数
}ElemType;

typedef struct Polynomial
{
    struct Elemtype Elem;
    Pnode* next;
}Pnode, * Polynomial;

//多项式的初始化
void InitPolynomial(Polynomial& P, int n)//n为项数
{
    P = new Pnode;
    P->next = NULL;//先建立一个头结点
    for (int i = 0;i < n;i++)//输入n次多项式数据
    {
        Pnode* s = new Pnode, * q = P->next, * pre = NULL;
        std::cin >> s->Elem.coef >> s->Elem.expn;//分别输入系数和指数
        while (q && s->Elem.expn > q->Elem.expn)
        {
            pre = q;
            q = q->next;
        }
        pre->next = s;
        s->next = q;
    }

}

//多项式的加法
