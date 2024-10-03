#include "type_definition.hpp"

int InitQueue(SqQueue& Q)
{
    Q.base = new QElemType[_INIT_SIZE];//分配数组空间
    if (!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}

int GetLenth(SqQueue Q)
{
    return ((Q.rear - Q.front + _INIT_SIZE) % _INIT_SIZE);
    //如果rear-front为正数，那%总大小就是相当于将加上的_INIT_SIZE减去了
    //如果rear-front为负数，此时表示空位个数，那加上_INIT_SIZE就是相当于总空间减掉空位得到长度。
}

int Enqueue(SqQueue& Q, QElemType E)
{
    if ((Q.rear + 1) % _INIT_SIZE == Q.front)//判断队列是否已满
        return ERROR;
    else
    {
        Q.base[Q.rear] = E;
        Q.rear = (Q.rear + 1) % _INIT_SIZE;
        return OK;
    }
}

int DeQueue(SqQueue& Q, QElemType& E)
{
    if (Q.front == Q.rear)//判断队内有无元素
        return ERROR;
    E = Q.base[Q.front];
    Q.front = (Q.front + 1) % _INIT_SIZE;
    return OK;
}

QElemType GetHead(SqQueue Q)
{
    if (Q.front != Q.rear)//队列不为空
        return Q.base[Q.front];
}