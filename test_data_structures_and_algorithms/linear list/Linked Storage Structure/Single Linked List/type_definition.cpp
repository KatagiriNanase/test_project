#include "type_definition.hpp"


int InitList_L(Linklist& L)
{
    L = new Lnode;
    L->next = NULL;
    return OK;
}//InitList_L

int IsEmpty(Linklist& L)
{
    if (!L->next)
        return 1;
    else
        return 0;
}//IsEmpty

int DestroyList(Linklist& L)
{
    Linklist p = NULL;
    while (L)
    {
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}//DestroyList

int ClearList(Linklist& L)
{
    Linklist p = L->next;
    Linklist q;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
    return OK;
}//ClearList

int Getlength(Linklist& L)
{
    int count = 0;
    Linklist p = L->next;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;

}//Getlength

int GetElem(Linklist L, int i, ElemType& e)
{
    Linklist p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j != i)
        return ERROR;
    else
        e = p->data;
    return OK;

}//GetElem

Lnode* LocateElem_pointer(Linklist L, ElemType e)
{
    Linklist p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}//LocateElem_pointer

int LocateElem_subscribe(Linklist L, ElemType e)
{
    Linklist p = L->next;
    int j = 1;
    while (p && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (!p)
        return ERROR;
    else
        return j;

}//LocateElem_subscribe

int InsertElem(Linklist& L, int i, ElemType e)
{
    Linklist p = L->next;
    int j = 1;
    while (p && j < i - 1)//将p指向i-1的位置
    {
        p = p->next;
        j++;
    }
    if (p && j == i - 1)
    {
        Linklist s = new Lnode;
        s->data = e;
        s->next = p->next;
        p->next = s;
        return OK;
    }
    else
        return ERROR;

}//InsertElem

int DeleteElem(Linklist& L, int i, ElemType& e)
{
    int j = 0;
    Linklist q = NULL, p = L;
    while (p->next || j < i - 1)//定位下标为i的值
    {
        p = p->next;
        j++;
    }

    if (!(p->next) || j > i - 1)
        return ERROR;
    else
    {
        q = p->next->next;
        e = p->data;
        delete p->next;
        p->next = q;
        return OK;
    }

}//DeleteElem

void CreateList_Head(Linklist& L, int n)
{
    L = new Lnode;
    L->next = NULL;
    for (int i = n;i > 0;i--)
    {
        Linklist p = new Lnode;
        std::cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}//CreateList_Head

void CreateList_Rear(Linklist& L, int n)
{
    Linklist r,L = new Lnode;
    L->next = NULL;
    r = L;
    for (int i = 0;i < n;i++)
    {
        Linklist p = new Lnode;
        std::cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}//CreateList_Rear

