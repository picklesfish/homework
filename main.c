#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"queue.h"

int main()
{
    int i,b,flag;
    char ch1,ch2='a';
    flag=2;
    AQueue *Q;
    Q=(AQueue*)malloc(sizeof(AQueue));

    InitLQueue(Q,flag);

    for(i=0;i<10;i++)
    {
        //ch1=ch2+i;
        EnLQueue(Q,&i);
    }
    for(i=0;i<10;i++)
    {
        DeLQueue(Q,&b);
        printf("%d\n",b);
    }

    //printf("%d\n",*( (int*)(Q->array) )+0 );
    getchar();
    //InitAQueue(AQueue *Q);
    return 0;
}

