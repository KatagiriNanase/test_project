#include "type_definition.h"
#include <stdlib.h>
typedef HPDataType  HPDataTypeArr[];
//堆排序
void HeapSortDesc(HPDataType* a, int n)//降序用小堆
{
    int HeapSize = n;//数组的大小
    //建小堆
    for (int i = (n - 1 - 1) / 2;i >= 0;i--)
        AdjustDownMin(a, n, i);
    while(HeapSize>1)
    {
        Swap(a, a + HeapSize - 1);
        //将数组的大小看为HeapSize-1
        HeapSize--;
        //此时堆顶的两个子树仍是小堆，此时在进行一次向下调整便可将次小的元素堆放到堆顶
        AdjustDownMin(a, HeapSize, 1 - 0);
        //将堆顶和最后一个元素交换
    }


}

void HeapSortAsc(HPDataType* a, int n)//升序用大堆
{
    int HeapSize = n;//数组的大小
    //建大堆
    for (int i = (n - 1 - 1) / 2;i >= 0;i--)
        AdjustDownMax(a, n, i);
    while (HeapSize > 1)
    {
        Swap(a, a + HeapSize - 1);
        //将数组的大小看为HeapSize-1
        HeapSize--;
        //此时堆顶的两个子树仍是小堆，此时在进行一次向下调整便可将次小的元素堆放到堆顶
        AdjustDownMax(a, HeapSize, 1 - 0);
        //将堆顶和最后一个元素交换
    }
}
int main()
{
    HPDataTypeArr a = { 27,15,19,18,28,34,65,49,25,37 };
    HeapSortAsc(a, sizeof(a) / sizeof(a[0]));
    return 0;

} 