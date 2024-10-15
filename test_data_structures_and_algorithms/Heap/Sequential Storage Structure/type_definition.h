#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//构建堆
typedef int HPDataType;
typedef struct Heap
{
    HPDataType* a;
    int size;//数组大小
    int capacity;//容量
}Heap;
void Swap(HPDataType* p1, HPDataType* p2);//交换数据

//向下调整法--前提：左右子树都是小堆
void AdjustDownMin(HPDataType* a, int n, int root);

//向下调整法--前提：左右子树都是大堆
void AdjustDownMax(HPDataType* a, int  n, int root);

//初始化堆
void HeapInit(Heap* php, HPDataType* e, int n);

//销毁堆
void HeapDestory(Heap* php);

//压入元素
void HeapPush(Heap* php, HPDataType e);

//弹出堆顶元素
void HeapPop(Heap* php);

//Top k元素
HPDataType Heaptop(Heap* php);


