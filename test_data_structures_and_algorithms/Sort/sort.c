#include "sort.h"

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void PrintArray(int* a, int n)
{
    int i = 0;
    while (i <= n - 1)
    {
        printf("%d ", a[i]);
        ++i;
    }
    printf("\n");
}

void InsertSort(int* a, int n)
{
    assert(a);

    for (int i = 0;i <= n - 2;i++)//end 只循环到(n-1)-1的下标中，不然后续访问a[end+1]就会越界
    {   //把第end个有序插入到已经有序的[0,end]数组中
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                --end;
            }
            else
                break;
        }
        a[end + 1] = tmp;
    }
}

void ShellSort(int* a, int n)
{
    //gap >1就相当于预排序，让数组接近有序
    //gap=1就相当于直接插入排序
    int gap = n;
    while (gap > 1)
    {
        //预排序
        gap = gap / 3 + 1;//+1保证了最后一次的gap一定是1，就能进行直接插入排序了
        for (int i = 0;i <= n - 1 - gap;i++)//后gap个已经不需要被排序了
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                    break;
            }
            a[end + gap] = tmp;

        }

    }
    InsertSort(a, n);

}

void SelectSort(int* a, int n)
{
    int begin = 0, end = n - 1;
    while (begin < end)
    {
        int max_sub, min_sub;
        max_sub = min_sub = begin;

        for (int i = begin + 1;i <= end;++i)
        {
            if (a[i] > a[max_sub])
                max_sub = i;

            if (a[i] < a[min_sub])
                min_sub = i;
        }

        //交换数据
        Swap(&a[begin], &a[min_sub]);
        //如果max和begin重合了，则max的位置会被换到min去了，因此max的位置要进行修正
        if (max_sub == begin)
            max_sub = min_sub;
        Swap(&a[end], &a[max_sub]);

        ++begin, --end;

    }
}

// 堆排序
//向下调整--大堆
void AdjustDown(int* a, int n, int root)
{
    int parent = root;
    int child = 2 * root + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child + 1] > a[child])
            ++child;

        if (a[child] > a[parent])
        {
            Swap(&a[parent], &a[child]);
            parent = child;
            child = 2 * parent + 1;
        }

        else
            break;
    }

}
void HeapSort(int* a, int n)
{
    //建堆
    for (int i = (n - 1 - 1) / 2;i >= 0;--i)
        AdjustDown(a, n, i);

    //排序
    while (n > 0)
    {
        Swap(a, &a[n - 1]);
        --n;
        AdjustDown(a, n, 0);
    }
}

void BubbleSort(int* a, int n)
{
    int end = n - 1;

    while (end >= 1)
    {
        int exchange = 0;
        for (int j = 0;j <= end - 1;j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
                exchange = 1;
            }
        }

        if (!exchange)//如果进循环后发现没有进行交换，说明已经是有序的了
            break;
        --end;
    }
}

//获取中间数下标
int GetMidIndex(int* a, int begin, int mid, int end)
{

    if (a[begin] > a[mid] > a[end] || a[end] > a[mid] > a[begin])
        return mid;

    if (a[begin] > a[end] > a[mid] || a[mid] > a[end] > begin)
        return end;

    if (a[end] > a[begin] > a[mid] || a[mid] > a[begin] > a[end])
        return begin;
}

int PartSort1(int* a, int left, int right)
{
    int end = right - 1, begin = left - 1;
    int keyindex = end;//key的下标

    while (begin < end)
    {
        //如果选最右边的值做key，那么要让左边的begin先走，这样让end去遇begin
        //停下来的位置才是大于key的数，交换后比key大的就会到后面

        while (begin < end && a[begin] < a[keyindex])
            ++begin;

        while (begin<end && a[end] > a[keyindex])
            --end;

        Swap(&a[begin], &a[end]);
    }

    Swap(&a[begin], &a[keyindex]);

    return begin;
}

int PartSort2(int* a, int left, int right)
{
    assert(a);
    int midindex = GetMidIndex(a, left, (left + right) / 2, right);
    Swap(&a[right], &a[midindex]);

    int keyindex = right;
    int key = a[keyindex];//此时最右边就相当于留下一个新坑
    int begin = left, end = right;

    while (begin < end)
    {
        while (begin < end && a[begin] <= key)
            ++begin;
        a[end] = a[begin];

        while (begin < end && a[end] >= key)
            --end;
        a[begin] = a[end];

    }

    a[begin] = key;

    return begin;
}

int PartSort3(int* a, int left, int right)
{
    assert(a);
    int midindex = GetMidIndex(a, left, (left + right) / 2, right);
    Swap(&a[right], &a[midindex]);

    int cur = left;
    int prev = left - 1;
    int key = a[right];

    while (cur < right)
    {
        if (a[cur] < key && ++prev != cur)
            Swap(&a[cur], &a[prev]);

        ++cur;
    }

    Swap(&a[++prev], &a[right]);

    return prev;
}

void QuickSort(int* a, int left, int right)
{
    assert(a);

    if (left >= right)//left 和 right 相遇就说明此区间只有一个元素，不需要再排了
        return;

    int div = PartSort1(a, left, right);
    //[left,div-1]  [div+1,right]

    QuickSort(a, left, div - 1);
    QuickSort(a, div + 1, right);
}
