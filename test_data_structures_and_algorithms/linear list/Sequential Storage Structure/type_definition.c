#include "type_definition.h"
#include <stdio.h>
void menu()
{
    printf("*******************************************\n");
    printf("***0.exit  ******************   1.Init******\n");
    printf("***2.DestroyList   *********   3.ClearList*\n");
    printf("***4.GetLength  ************    5.IsEmpty**\n");
    printf("***6.GetElem  **************   7.LocateElem\n");
    printf("***8.Insert     ***********   9.Delete\n");
    printf("***10.show***\n");

    printf("select options:");
}

void ShowList(Sqlist* L)
{
    if (!L->length)
        puts("none!\n");
    else
        for (int i = 0; i < L->length; i++)
        {
            printf("%d ", L->elem[i]);
        }
    puts("\n");
}

int InitList_Sq(Sqlist* L) // 初始化线性表
{
    L->elem = (ElemType*)malloc(sizeof(ElemType) * _INIT_SIZE);
    if (!L)
    {
        printf(strerror(errno));
    }
    else
        L->length = 0;
    return OK;
}

int DestroyList(Sqlist* L) // 销毁线性表
{
    if (L)
    {
        free(L->elem);
        L->elem = NULL;
        return OK;
    }
}

int ClearList(Sqlist* L) // 清空线性表
{
    L->length = 0;
}

int GetLength(Sqlist* L)
{
    return L->length;
}

int IsEmpty(Sqlist* L)
{
    if (L->length == 0)
        return 1;
    else
        return 0;
}

int GetElem(Sqlist* L, int i, ElemType e)
{
    if (i < 1 || i > L->length)
        return ERROR;
    else
    {
        e = L->elem[i - 1];
        return OK;
    }
}

int LocateElem(Sqlist* L, ElemType e)
{
    if (!L->length)
        return ERROR;
    int i = 1;
    // while(i++<L.length)
    // {
    //     if(L.elem[i-1]==e)
    //         return i;
    // }
    // return 0;
    while (i <= L->length && L->elem[i - 1] != e)
        i++;
    if (i <= L->length)
        return i;
    else
        return 0;
}

int InsertList(Sqlist* L, int i, ElemType e)
{
    if (L->length == SIZE_MAX)
        return OVERFLOW;
    if (i < 1 || i > L->length + 1)
        return ERROR;
    // for (j = 0; j < L->length - i + 1; j++)
    // {
    //     L->elem[L->length - j] = L->elem[L->length - 1 - j];
    // }
    int j = L->length;
    for (j; j > i - 1; j--)
        L->elem[j] = L->elem[j - 1];
    L->elem[i - 1] = e;
    L->length++;
    return OK;
}
int DeleteList(Sqlist* L, int i)
{
    if (i < 1 || i > L->length)
        return ERROR;
    int j = i - 1;
    for (j; j < L->length - 1; j++)
        L->elem[j] = L->elem[j + 1];
    L->length--;
    return OK;
}

void MergeSqlist(Sqlist* Sqa, Sqlist* Sqb, Sqlist* Sqc)
{
    InitList_Sq(Sqc);
    int Sqa_len = GetLength(Sqa);
    int Sqb_len = GetLength(Sqb);
    ElemType* pa = Sqa->elem, * pb = Sqb->elem;
    int i = 0, j = 0, k = 0;
    while (i < Sqa_len && j < Sqb_len)
    {
        if (pa[i] <= pb[j])
            InsertList(Sqc, k++, pa[i++]);
        else
            InsertList(Sqc, k++, pb[j++]);

    }
    if (i <= Sqa_len)
        for (j;j < Sqb_len;j++)
            InsertList(Sqc, k++, pb[j]);
    if (j <= Sqb_len)
        for (i;i < Sqa_len;i++)
            InsertList(Sqc, i, pa[i]);


}//MergeSqlist 
//下次用指针来当判断条件吧，感觉更方便，还不用一直数数
