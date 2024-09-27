#include "type_definition.hpp"


int InitList_L(Linklist& L)
{
    L = new Lnode;
    L->next = L;
    return OK;
}//InitList_L

Linklist ConnectList(Linklist Ta, Linklist Tb)
{
    if (Ta->next == Ta || Tb->next == Tb)
        return NULL;
    else
    {
        Linklist Tc = new Lnode;
        Tc = Ta->next;
        Ta->next = Tb->next->next;
        delete Tb->next;
        Tb->next = Tc;
        return Tb;
    }

}//ConnectList

int IsEmpty(Linklist& L)
{
    if (L->next==L)
        return 1;
    else
        return 0;
}//IsEmpty

