#include "type_definition.hpp"

DuLinklist LocateElem_pointer(DuLinklist& L, int i)
{
    int j = 0;
    DuLinklist p = L;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return NULL;
    else
        return p;
}//LocateElem

int InsertElem(DuLinklist& L, int i, ElemType e)
{
    // int j = 0;
    // DuLinklist p = L;
    // while (p->next && j < i)
    // {
    //     p = p->next;
    //     j++;
    // }
    DuLinklist p;
    if (!(p = LocateElem_pointer(L, i)))
        return ERROR;
    else
    {
        DuLinklist s = new DuLnode;
        s->data = e;
        s->prior = p->prior;
        s->next = p;
        p->prior->next = s;
        p->prior = s;
        return OK;
    }
}//InsertElem

int DeleteElem(DuLinklist& L, int i, ElemType& e)
{
    DuLinklist p;
    if (!(p = LocateElem_pointer(L, i)))
        return ERROR;
    else
    {
        e = p->data;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        delete p;
        return OK;
    }
}//DeleteElem
