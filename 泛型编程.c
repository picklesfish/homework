#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
#define Max 100

typedef struct queue
{
    void *array;
    int first;
    int end;
}AQueue;

typedef enum
{
    false,
    ture
}Status;

/*void InitAQueue(AQueue *Q)
{
    void *Array;
    Array=malloc(MAX);
    Q->array=Array;
    Q->first=0;
    Q->end=0;
}
*/

//初始化队列
void InitAQueue(AQueue *Q)
{
    void *Array;
    Array=malloc(MAX);
    Q->array=Array;
    Q->first=0;
    Q->end=0;
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
    if(Q->end == Max)
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
Status GetHeadAQueue(AQueue *Q,void *e,int size)
{
    if(IsEmptyAQueue(Q))
        return;
    void *elemAddr;
    //char型只有一个字节，所以可以将基类型强制转换为char型，再加上相应的长度实现地址的偏移
    elemAddr=(char*)(Q->array)+(Q->first)*size;
    memcpy(e,elemAddr,size);
}

//进队
void InAQueue(AQueue *Q,void *x,int size)
{
    if(IsFullAQueue(Q))
        return;
    void *elemAddr;
    elemAddr=(char*)(Q->array)+(Q->end)*size;
    memcpy(elemAddr,x,size);
    Q->end++;
}

//出队
void OutAQueue(AQueue *Q,void *y,int size)
{
    if(IsEmptyAQueue(Q))
        return;
    void *elemAddr;
    elemAddr=(char*)(Q->array)+(Q->first)*size;
    memcpy(y,elemAddr,size);
    Q->first++;
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


int main()
{
    AQueue *Q;
    Q=(AQueue*)malloc(sizeof(AQueue));
    InitAQueue(Q);
    int i;
    int b;
    char ch1,ch2='a';
    for(i=0;i<10;i++)
    {
        ch1=ch2+i;
        InAQueue(Q,&ch1,sizeof(char));
    }
    for(i=0;i<10;i++)
    {
        OutAQueue(Q,&ch1,sizeof(char));
        printf("%c\n",ch1);
    }

    //printf("%d\n",*( (int*)(Q->array) )+0 );
    getchar();
    //InitAQueue(AQueue *Q);
}
