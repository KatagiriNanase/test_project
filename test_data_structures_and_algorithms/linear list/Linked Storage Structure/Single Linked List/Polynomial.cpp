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
void AddPolynomial(Polynomial& Pa, Polynomial& Pb)
{
    Pnode* p1 = Pa->next, * p2 = Pb->next, * pre = Pa;//pre用来记录当前接上的最后一个节点
    while (p1 && p2)//不为null时才循环
    {
        if (p1->Elem.expn = p2->Elem.expn)//指数相同的时候
        {
            if (p1->Elem.coef + p2->Elem.coef)//如果系数相加为零，则删除两个节点
            {
                Pnode* ptmp1 = p1, * ptmp2 = p2;
                p1 = p1->next;
                p2 = p2->next;
                delete ptmp1, ptmp2;
            }
            else
            {
                p1->Elem.coef = p1->Elem.coef + p2->Elem.coef;//系数相加不为零，则相加放入p1中
                pre = p1;
                Pnode* ptmp = p2;
                p2 = p2->next;
                p1 = p1->next;
                delete ptmp;//删除p2节点
            }
        }
        else//指数不相同的时候
        {
            if (p1->Elem.expn < p2->Elem.expn)//哪个指数小pre就接上哪个
            {
                pre->next = p1;
                pre = p1;
                p1 = p1->next;
            }
            else
            {
                pre->next = p2;
                pre = p2;
                p2 = p2->next;
            }

        }
    }
    p1 = (p1 ? p1 : p2);//让不为空的那个指针赋值给p1;
    pre->next = p1;
    delete Pb;//释放Pb；
}
