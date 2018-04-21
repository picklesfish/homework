#ifndef QUEUE_H_INCLUDE
#define QUEUE_H_INCLUDE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

//顺序队列结构体
typedef struct queue
{
    void *array;
    int first;
    int end;
    int length;             //队列的长度
    int size;               //数据域内存的大小
}AQueue;

typedef enum
{
    false,
    ture
}Status;

//链式队列结构体
typedef struct node
{
    void *data;
    struct node *next;
}Node;

typedef struct Lqueue
{
    Node *front;
    Node *rear;
    int length;             //队列的长度
    int size;               //数据域内存的大小
}LQueue;


#endif // QUEUE_H_INCLUDE

/**************顺序队列*******************/

//初始化队列,根据形参flag决定数据的类型，1为char型。2为int型。
void InitAQueue(AQueue *Q,int flag);

//销毁队列
void DestoryAQueue(AQueue *Q);

//判断是否队列已满
Status IsFullAQueue(const AQueue *Q);

//判断是否为空
Status IsEmptyAQueue(const AQueue *Q);

//获取队首元素
Status GetHeadAQueue(AQueue *Q,void *e);

//进队
void InAQueue(AQueue *Q,void *data);

//出队
void OutAQueue(AQueue *Q,void *data);

//清空队列
void ClearAQueue(AQueue *Q);



/*******************链式队列***********************/

