#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

typedef struct queue
{
    void *array;
    int first;
    int end;
}AQueue;

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
void destoryAQueue(AQueue *Q)
{
    free(Q->array);
    free(Q);
}

//进队
void inAQueue(AQueue *Q,void *x,int size)
{
    void *elemAddr;
    elemAddr=(char*)(Q->array)+(Q->end)*size;
    memcpy(elemAddr,x,size);
    Q->end++;
}

int main()
{
    AQueue *Q;
    Q=(AQueue*)malloc(sizeof(AQueue));
    InitAQueue(Q);
    int a=9;
    inAQueue(Q,&a,sizeof(int));
    printf("%d\n",*( (int*)(Q->array) )+0 );
    getchar();
    //InitAQueue(AQueue *Q);
}
