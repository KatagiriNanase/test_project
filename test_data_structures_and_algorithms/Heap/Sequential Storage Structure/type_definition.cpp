#include "type_definition.hpp"

//初始化堆
void HeapInit(Heap* php, HPDataType* e, int n)
{
    php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);//开辟一个和传入数组大小相同的空间
    memcpy(php->a, e, sizeof(HPDataType) * n);//将数据迁移到我们定义的堆中的数组
    php->size = n;
    php->capacity = n;

    //构建堆

}

//销毁堆
void HeapDestory(Heap* php);

//压入元素
void HeapPush(Heap* php, HPDataType e);

//弹出堆顶元素
void HeapPop(Heap* php);

//Top k元素
HPDataType Heaptop(Heap* php);