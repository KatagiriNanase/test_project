#include "type_definition.h"
#include <stdio.h>

int main()
{
    Sqlist L = {0};
    int choose = -1;
    printf("Test for sequence list\n");
    do
    {
        printf("\n");
        menu();
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:
            puts("bye\n");
            break;
        case 1:
            if (InitList_Sq(&L))
                puts("init successfully!");
            else
                printf("error!\n");
            break;
        case 2:
            DestroyList(&L);
            break;
        case 3:
            ClearList(&L);
            break;
        case 4:
            printf("%d\n", GetLength(&L));
            break;
        case 5:
            if (IsEmpty(&L))
                printf("Yes!\n");
            else
                printf("No!\n");
            break;
        case 6:
            puts("input the subscript:");
            int i1;
            ElemType e1;
            scanf("%d", &i1);
            GetElem(&L, i1, e1);
            printf("get the elem:%d\n", e1);
            break;
        case 7:
            puts("input the elem:");
            int i2;
            ElemType e2;
            scanf("%d", &e2);
            if (i2 = LocateElem(&L, e2))
                printf("the subscript is %d\n", i2);
            else
                puts("error\n");

            break;
        case 8:
            puts("input the subscript:");
            int i3;
            ElemType e3;
            scanf("%d", &i3);
            puts("input the element:");
            scanf("%d", &e3);
            if (InsertList(&L, i3, e3))
                printf("insert successfully!\n");
            else
                puts("error\n");
            break;
        case 9:
            puts("input the subscript:");
            int i4;
            ElemType e4;
            scanf("%d", &i4);
            puts("input the element:");
            if (DeleteList(&L, i4))
                puts("deleted successfully!\n");
            else
                puts("error!\n");
            break;
        case 10:
            ShowList(&L);
            break;
        default:
            puts("input error! reinput:");
            break;
        }

    } while (choose);

    return 0;
}