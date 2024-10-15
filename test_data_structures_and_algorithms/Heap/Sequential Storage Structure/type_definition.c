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
    child = 2 * parent;//默认给他个左孩子
    while (child <= n)//当左右孩子的下标存在于数组当中才进行循环
    {
        //将左右孩子中较小的再赋值给child
        //while只判定了左孩子，有一种极端的情况为左孩子存在但是右孩子越界
        //因此要保证child+1是不能越界的 
        if (child + 1 <= n && a[child] > a[child - 1])
            ++child;
        if (a[child - 1] > a[parent - 1])
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
void HeapDestory(Heap* php);

//压入元素
void HeapPush(Heap* php, HPDataType e);

//弹出堆顶元素
void HeapPop(Heap* php);

//Top k元素
HPDataType Heaptop(Heap* php);