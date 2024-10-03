#include "type_definition.hpp"

int InitQueue(LinkQueue& Q)
{
    Q.front = Q.rear = new Qnode;
    Q.front->next = NULL;
    return OK;
}

int DestroyQueue(LinkQueue& Q)
{
    while (Q.front)
    {
        // QueuePtr p = Q.front;
        // Q.front = Q.front->next;
        // delete p;
        Q.rear = Q.front;//rear留着也没用，就用来记录front的上一位置。
        Q.front = Q.front->next;
        delete Q.rear;
    }
    Q.rear = NULL;
    return OK;
}

int EnQueue(LinkQueue& Q, QElemType E)
{
    Qnode* p = new Qnode;
    p->data = E;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

int DeQueue(LinkQueue& Q, QElemType& E)
{
    if (Q.front == Q.rear)
        return ERROR;
    E = Q.front->next->data;
    Qnode* p = Q.front->next;
    Q.front = p->next;
    if (p == Q.rear)//如果p所保留的就是尾指针的话，那出队后就没有元素了，那rear就要重置为和front相等。or Q.front->next=NULL;
        Q.rear = Q.front;
    delete p;
    return OK;

}

int GetHead(LinkQueue Q, QElemType& E)
{
    if (Q.front == Q.rear)
        return ERROR;
    E = Q.front->next->data;
    return OK;
}