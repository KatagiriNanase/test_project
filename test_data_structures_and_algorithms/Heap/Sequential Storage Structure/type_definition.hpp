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


