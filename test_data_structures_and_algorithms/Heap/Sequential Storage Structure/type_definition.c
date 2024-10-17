#include "type_definition.h"
void Swap(HPDataType* p1, HPDataType* p2)//交换数据
{
    HPDataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

//向下调整法--前提：左右子树都是小堆
void AdjustDownMin(HPDataType* a, int  n, int root)//root为想要调整的根节点
{
    int parent = root, child;//下标
    child = 2 * parent;//默认给他个左孩子
    while (child <= n)//当左右孩子的下标存在于数组当中才进行循环
    {
        //将左右孩子中较小的再赋值给child
        //while只判定了左孩子，有一种极端的情况为左孩子存在但是右孩子越界
        //因此要保证child+1是不能越界的 
        if (child + 1 <= n && a[child] < a[child - 1])
            ++child;
        if (a[child - 1] < a[parent - 1])
        {
            Swap(a + parent - 1, a + child - 1);
            parent = child;//将指针变为自己的较小的孩子 
            child = 2 * parent;
        }
        //如果孩子已经大于双亲了，说明已经调整完毕了
        else
            break;
    }

}

void AdjustDownMax(HPDataType* a, int  n, int root)//root为想要调整的根节点
{
    int parent = root, child;//下标
    child = 2 * parent + 1;//默认给他个左孩子
    while (child <= n)//当左右孩子的下标存在于数组当中才进行循环
    {
        //将左右孩子中较小的再赋值给child
        //while只判定了左孩子，有一种极端的情况为左孩子存在但是右孩子越界
        //因此要保证child+1是不能越界的 
        if (child + 1 <= n && a[child + 1] > a[child])
            ++child;
        if (a[child] > a[parent])
        {
            Swap(a + parent, a + child);
            parent = child;//将指针变为自己的较小的孩子 
            child = 2 * parent + 1;
        }
        //如果孩子已经大于双亲了，说明已经调整完毕了
        else
            break;
    }

}

//初始化堆--堆顶传入下标默认为1
void HeapInit(Heap* php, HPDataType* e, int  n)
{
    php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);//开辟一个和传入数组大小相同的空间
    memcpy(php->a, e, sizeof(HPDataType) * n);//将数据迁移到我们定义的堆中的数组
    php->size = n;
    php->capacity = n;

    //构建堆
    for (int i = (n - 1 - 1) / 2;i <= 0;i--)
        AdjustDownMin(php->a, php->size, i);

}

//销毁堆
void HeapDestory(Heap* php)
{
    assert(php);
    free(php->a);
    php->a = NULL;
    php->capacity = php->size = 0;

}

//向上调整法
void AdjustUp(HPDataType* a, int size, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (a[child] < a[parent])
        {
            Swap(&a[child], &a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
            break;
    }
}
//压入元素
void HeapPush(Heap* php, HPDataType e)
{
    assert(php);
    if (php->size == php->capacity)//满了扩容
    {
        php->a = (HPDataType*)realloc(php->a, sizeof(HPDataType) * (php->size) * 2);
        php->capacity *= 2;
    }
    php->a[php->size] = e;//在尾部插入元素，此时并不会改变原有的大小堆结构
    php->size++;//元素个数加一
    AdjustUp(php->a, php->size, php->size - 1);//向上调整

}

//删除堆顶元素
void HeapPop(Heap* php)
{
    Swap(php->a, (php->a) + php->size - 1);//仍然是堆顶元素和最后一个元素交换，从而 保留了原有的堆的结构
    --php->size;
    AdjustDownMin(php->a, php->size, 0);
}

//Top k元素--排最小的前十个--建大堆
HPDataType* Heaptop(Heap* php, int k)
{
    assert(php);
    //对前k个数进行建堆
    HPDataType* ret_arr = (HPDataType*)malloc(sizeof(HPDataType) * k);
    memcpy(ret_arr, php->a, sizeof(HPDataType) * k);
    for (int i = (k - 1 - 1) / 2;i >= 0;i--)//迭代向下调整法进行建大堆
        AdjustDownMax(ret_arr, k, i);
    for (int i = k;i <= php->size - 1;i++)//将Heap中剩余的元素拿过来一一比较
    {
        if (php->a[i] < ret_arr[0])//如果php->a中的元素比ret_arr的堆顶大就进堆里去
        {
            Swap(&php->a[i], &ret_arr[0]);
            AdjustDownMax(ret_arr, k, 0);
        }
    }

    //排序
    while (k > 0)
    {
        Swap(ret_arr, &ret_arr[k - 1]);//交换首位两个元素，堆原有结构不变
        --k;
        AdjustDownMax(ret_arr, k - 1, 0);//对堆顶进行一次向下调整，就又会变成大堆
    }
    return ret_arr;


}