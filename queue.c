#include"queue.h"

/**************顺序队列**********************/

//初始化队列
void InitAQueue(AQueue *Q,int flag)
{
    void *Array;
    if(flag == 1)
        Q->size=sizeof(char);
    if(flag == 2)
        Q->size=sizeof(int);
    Q->first=0;
    Q->end=0;
    Q->length=MAX;
    Array=malloc((Q->size)*(Q->length));
    Q->array=Array;
}

//销毁队列
void DestoryAQueue(AQueue *Q)
{
    free(Q->array);
    free(Q);
}

//判断是否队列已满
Status IsFullAQueue(const AQueue *Q)
{
    if((Q->end+1)%(Q->length) == Q->first)
        return ture;
    return false;
}

//判断是否为空
Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->first == Q->end)
        return ture;
    return false;
}

//获取队首元素
Status GetHeadAQueue(AQueue *Q,void *e)
{
    if(IsEmptyAQueue(Q))
        return;
    void *elemAddr;
    //char型只有一个字节，所以可以将基类型强制转换为char型，再加上相应的长度实现地址的偏移
    elemAddr=(char*)(Q->array)+(Q->first)*(Q->size);
    memcpy(e,elemAddr,Q->size);
}

//进队
void InAQueue(AQueue *Q,void *data)
{
    if(IsFullAQueue(Q))
        return;
    void *elemAddr;
    elemAddr=(char*)(Q->array)+(Q->end)*(Q->size);
    memcpy(elemAddr,data,Q->size);
    Q->end=(Q->end++)%(Q->length);
}

//出队
void OutAQueue(AQueue *Q,void *data)
{
    if(IsEmptyAQueue(Q))
        return;
    void *elemAddr;
    elemAddr=(char*)(Q->array)+(Q->first)*(Q->size);
    memcpy(data,elemAddr,Q->size);
    Q->first=(Q->first++)%(Q->length);
}

//清空队列
void ClearAQueue(AQueue *Q)
{
    Q->first=0;
    Q->end=0;
}

//遍历队列
Status TraverseAQueue(const AQueue *Q,void (*foo)(void *q))
{
    ;
}

void APrint(void *q)
{
    ;
}

/***************链式队列*******************/
//初始化队列,根据形参flag决定数据的类型，1为char型。2为int型。
void InitLQueue(LQueue *Q,int flag)
{
    if(flag == 1)
        Q->size=sizeof(char);
    if(flag == 2)
        Q->size=sizeof(int);
    Node *p;
    p=malloc(Q->size);
    p->next=NULL;
    Q->front=p;
    Q->rear=p;
    Q->length=0;
}

//销毁链表
void DestroyLQueue(LQueue *Q)
{
    Node *p1,*p2;
    p1=Q->front;
    while(p1!=NULL)
    {
        p2=p1->next;
        free(p1);
        p1=p2;
    }
    free(Q);
}

//判断队列是否为空
Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->front == Q->rear)
        return ture;
    return false;
}

//查看队首元素
Status GetHeadLQueue(LQueue *Q,void *e)
{
    if(IsEmptyLQueue(Q))
        return false;
    Node *p=Q->front->next;
    memcpy(e,p->data,Q->size);
    return ture;
}

//获取队列长度
int LengthLQueue(LQueue *Q)
{
    if(Q!=NULL)
        return Q->length;
    return 0;
}

//入队
Status EnLQueue(LQueue *Q,void *data)
{
    Node *p;
    p=malloc(Q->size);
    if((Q == NULL) || (p == NULL))
        return false;
    p->next=NULL;
    Q->rear->next=p;
    memcpy(p->data,data,Q->size);
    Q->rear=p;
    Q->length++;
    return ture;
}

//出队
Status DeLQueue(LQueue *Q,void *data)
{
    if((Q == NULL) || IsEmptyLQueue(Q))
        return false;
    Node *p=Q->front->next;
    memcpy(data,p->data,Q->size);
    free(Q->front);
    Q->front=p;
    Q->length--;
    return ture;
}

//清空队列
void ClearLQueue(LQueue *Q)
{
    Node *p=Q->front;
    while(Q->front!=Q->rear)
    {
        free(Q->front);
        Q->front=p;
        p=p->next;
    }
    Q->length=0;
}



