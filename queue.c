#include<windows.h>
#include"queue.h"

int flag;
AQueue *AQ=NULL;
LQueue *LQ=NULL;

/**************顺序队列**********************/

//初始化队列
void InitAQueue(AQueue *Q,int flag)
{
    void *Array;
    if(flag == 1)                   //flag标记为1表示数据类型为char型，2为int型
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
void DestroyAQueue(AQueue *Q)
{
    free(Q->array);
    free(Q);
}

//判断是否队列已满
Status IsFullAQueue(const AQueue *Q)
{
    if(Q->end == Q->length)
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
        return  false;
    void *elemAddr;
    //char型只有一个字节，所以可以将基类型强制转换为char型，
    //再加上相应的长度实现地址的偏移，下面的与此相同
    elemAddr=(char*)(Q->array)+(Q->first)*(Q->size);
    //将指针elemAddr开始的Q->size个字节的数据复制到指针e指向的地址中
    memcpy(e,elemAddr,Q->size);
    return ture;
}

//查看当前队列长度
int LengthAQueue(AQueue *Q)
{
    if((Q == NULL) || IsEmptyAQueue(Q))
        return 0;
    else
        return (Q->end - Q->first);
}

//进队
Status InAQueue(AQueue *Q,void *data)
{
    if(IsFullAQueue(Q))
        return false;
    void *elemAddr;
    elemAddr=(char*)(Q->array)+(Q->end)*(Q->size);
    memcpy(elemAddr,data,Q->size);
    Q->end++;
    return ture;
}

//出队
Status OutAQueue(AQueue *Q,void *data)
{
    if(IsEmptyAQueue(Q))
        return false;
    void *elemAddr;
    elemAddr=(char*)(Q->array)+(Q->first)*(Q->size);
    memcpy(data,elemAddr,Q->size);
    Q->first++;
    return ture;
}

//清空队列
void ClearAQueue(AQueue *Q)
{
    Q->first=0;
    Q->end=0;
}

//遍历队列
Status TraverseAQueue(const AQueue *Q,void (*foo)(AQueue *Q,void *q))
{
    if((Q == NULL) || IsEmptyAQueue(Q))
        return false;
    int length;
    length=(Q->end) - (Q->first);
    Output_Table((length-1)/3+1);
    int i,j=0,k=0;
    void *elemAddr;
    i=Q->first;
    while(i < Q->end)
    {
        if(k == 3)
        {
            k=0;
            j++;
        }
        goto_xy(11+20*k,8+j*2);
        elemAddr=(char*)(Q->array)+i*(Q->size);
        foo(Q,elemAddr);
        i++;
        k++;
    }
    return ture;
}

void APrint(AQueue *Q,void *q)
{
    int a;
    char b;
    if(Q->size == sizeof(char))
    {
        memcpy(&b,q,Q->size);
        printf("%c",b);
    }
    if(Q->size == sizeof(int))
    {
        memcpy(&a,q,Q->size);
        printf("%d",a);
    }
}



/***************************链式队列*************************************/
//初始化队列,根据形参flag决定数据的类型，1为char型。2为int型。
void InitLQueue(LQueue *Q,int flag)
{
    if(flag == 1)
        Q->size=sizeof(char);
    if(flag == 2)
        Q->size=sizeof(int);
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    p->data=malloc(Q->size);
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
    if((Q == NULL) || IsEmptyLQueue(Q))
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
    p=(Node*)malloc(sizeof(Node));
    p->data=malloc(Q->size);
    if((Q == NULL) || (p == NULL) || (p->data == NULL))
        return false;
    p->next=NULL;
    (Q->rear)->next=p;

    /******
        printf("   ");
        之前p->data没有分配地址，导致memcpy函数出错，可是不知道为什么加了printf以后程序就没有崩，虽然也是错的。
    *******/
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
    Node *p=Q->front->next;
    while(Q->front!=Q->rear)
    {
        free(Q->front);
        Q->front=p;
        p=p->next;
    }
    Q->length=0;
}

//遍历队列
Status TraverseLQueue(const LQueue *Q,void (*foo)(LQueue *Q,void *q))
{
    if((Q == NULL) || (IsEmptyLQueue(Q)))
        return false;
    Output_Table((Q->length-1)/3+1);
    int j=0,k=0;
    Node *p;
    p=Q->front;
    while(p!=Q->rear)
    {
        if(k == 3)
        {
            k=0;
            j++;
        }
        goto_xy(11+20*k,8+j*2);
        p=p->next;
        foo(Q,p->data);
        k++;
    }
    return ture;
}

void LPrint(LQueue *Q,void *q)
{
    int a;
    char b;
    if(Q->size == sizeof(int))
    {
        memcpy(&a,q,Q->size);
        printf("%d",a);
    }
    if(Q->size == sizeof(char))
    {
        memcpy(&b,q,Q->size);
        printf("%c",b);
    }
}


/***********菜单************/

//控制光标函数，使光标跳转到（X，Y）坐标上
void goto_xy(int x,int y)
{
    HANDLE hOut;
    COORD pos={0,0};
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hOut,pos);
}

void Output_Table(int n)                        //创建输出表格
{
    int i,j;
    for(i=0;i<n;i++)
    {
        goto_xy(10,7+i*2);
        printf("——————————————————————————————");
        for(j=0;j<4;j++)
        {
            goto_xy(10+20*j,8+i*2);
            printf("|");
        }
    }
    goto_xy(10,7+i*2);
    printf("——————————————————————————————");
}


//顺序队列菜单
void nemuAQueue()
{
    int a,status;
    int x;
    char ch;
    void (*foo)(AQueue *Q,void *q);
    foo=&APrint;

    Output_Table(3);
    goto_xy(30,6);
    printf("顺序队列菜单");
    goto_xy(11,8);
    printf("1.创建队列");
    goto_xy(31,8);
    printf("2.销毁队列");
    goto_xy(51,8);
    printf("3.获取队首元素");
    goto_xy(11,10);
    printf("4.查看队列长度");
    goto_xy(31,10);
    printf("5.进队");
    goto_xy(51,10);
    printf("6.出队");
    goto_xy(11,12);
    printf("7.清空队列");
    goto_xy(31,12);
    printf("8.遍历队列");
    goto_xy(51,12);
    printf("9.退出");

    goto_xy(20,14);
    printf("请输入你要操作前的数字：");
    scanf("%d",&a);

    system("cls");
    switch(a)
    {
        case 1: //创建
                goto_xy(30,9);
                printf("请选择数据类型：（1.char   2.int）");
                scanf("%d",&flag);
                InitAQueue(AQ,flag);
                goto_xy(30,10);
                printf("创建成功");
                break;

        case 2: //销毁
                DestroyAQueue(AQ);
                goto_xy(30,10);
                printf("销毁成功");
                break;

        case 3: //访问队首
                goto_xy(30,10);
                if(flag == 1)
                {
                    getchar();
                    status=GetHeadAQueue(AQ,&ch);
                    if(status == ture)
                        printf("队首元素为%c",ch);
                    else
                        printf("队列为空");
                }
                if(flag == 2)
                {
                    status=GetHeadAQueue(AQ,&x);
                    if(status == ture)
                        printf("队首元素为%d",x);
                    else
                        printf("队列为空");
                }
                break;

        case 4: //求队列长度
                x=LengthAQueue(AQ);
                goto_xy(30,10);
                printf("队列长度为%d",x);
                break;

        case 5: //进队
                goto_xy(30,10);
                printf("请输入进队数据：");
                getchar();
                if(flag == 1)
                {
                    scanf("%c",&ch);
                    getchar();
                    InAQueue(AQ,&ch);
                }
                if(flag == 2)
                {
                    scanf("%d",&x);
                    getchar();
                    InAQueue(AQ,&x);
                }
                goto_xy(30,11);
                printf("成功！");
                break;

        case 6: //出队
                goto_xy(30,10);
                if(flag == 1)
                {
                    OutAQueue(AQ,&ch);
                    printf("出队元素为：%c",ch);
                }
                if(flag == 2)
                {
                    OutAQueue(AQ,&x);
                    printf("出队元素为：%d",x);
                }
                break;

        case 7: //清空
                ClearAQueue(AQ);
                goto_xy(30,10);
                printf("清空完毕！");
                break;

        case 8: //遍历
                if(TraverseAQueue(AQ,foo) == false)
                {
                    goto_xy(30,10);
                    printf("队列为空！");
                }
                else
                {
                    goto_xy(20,6);
                    printf("队列如下：");
                }
                break;

        case 9: //退出
                nemu();
                break;

        default:goto_xy(30,10);
                printf("输入错误，请重试！");

    }
    Sleep(1000);
    system("cls");
    nemuAQueue();
}

//链式队列菜单
void nemuLQueue()
{
    int a,status;
    int x;
    char ch;
    void (*foo)(LQueue *Q,void *q);
    foo=&LPrint;

    Output_Table(3);
    goto_xy(30,6);
    printf("链式队列菜单");
    goto_xy(11,8);
    printf("1.创建队列");
    goto_xy(31,8);
    printf("2.销毁队列");
    goto_xy(51,8);
    printf("3.获取队首元素");
    goto_xy(11,10);
    printf("4.查看队列长度");
    goto_xy(31,10);
    printf("5.进队");
    goto_xy(51,10);
    printf("6.出队");
    goto_xy(11,12);
    printf("7.清空队列");
    goto_xy(31,12);
    printf("8.遍历队列");
    goto_xy(51,12);
    printf("9.退出");

    goto_xy(20,14);
    printf("请输入你要操作前的数字：");
    scanf("%d",&a);
    getchar();

    system("cls");
    switch(a)
    {
        case 1: //创建
                goto_xy(30,9);
                printf("请选择数据类型：（1.char   2.int）");
                scanf("%d",&flag);
                getchar();
                while((flag!=1) && (flag!=2))
                {
                    goto_xy(30,10);
                    printf("                           ");
                    goto_xy(30,10);
                    printf("输入错误，请重新输入：");
                    scanf("%d",&a);
                }
                InitLQueue(LQ,flag);
                goto_xy(30,10);
                printf("创建成功");
                break;

        case 2: //销毁
                DestroyLQueue(LQ);
                goto_xy(30,10);
                printf("销毁成功");
                break;

        case 3: //访问队首
                goto_xy(30,10);
                if(flag == 1)
                {
                    status=GetHeadLQueue(LQ,&ch);
                    if(status == ture)
                        printf("队首元素为%c",ch);
                    else
                        printf("队列为空");
                }
                if(flag == 2)
                {
                    status=GetHeadLQueue(LQ,&x);
                    if(status == ture)
                        printf("队首元素为%d",x);
                    else
                        printf("队列为空");
                }
                break;

        case 4: //求队列长度
                x=LengthLQueue(LQ);
                goto_xy(30,10);
                printf("队列长度为%d",x);
                break;

        case 5: //进队
                goto_xy(30,10);
                printf("请输入进队数据：");
                if(flag == 1)
                {
                    scanf("%c",&ch);
                    getchar();
                    EnLQueue(LQ,&ch);
                }
                if(flag == 2)
                {
                    scanf("%d",&x);
                    getchar();
                    EnLQueue(LQ,&x);
                }
                goto_xy(30,11);
                printf("成功！");
                break;

        case 6: //出队
                goto_xy(30,10);
                if(flag == 1)
                {
                    if(DeLQueue(LQ,&ch) == ture)
                        printf("出队元素为：%c",ch);
                    else
                    {
                        goto_xy(30,10);
                        printf("队列为空");
                    }
                }
                if(flag == 2)
                {
                    if(DeLQueue(LQ,&x) == ture)
                        printf("出队元素为：%d",x);
                    else
                    {
                        goto_xy(30,10);
                        printf("队列为空");
                    }
                }
                break;

        case 7: //清空
                ClearLQueue(LQ);
                goto_xy(30,10);
                printf("清空完毕！");
                break;

        case 8: //遍历
                if(TraverseLQueue(LQ,foo) == ture)
                {
                    goto_xy(20,6);
                    printf("队列数据如下：");
                }
                else
                {
                    goto_xy(30,10);
                    printf("队列为空！");
                }
                break;

        case 9: //退出
                nemu();
                break;

        default:goto_xy(30,10);
                printf("输入错误，请重试");
                break;
    }
    Sleep(1000);
    system("cls");
    nemuLQueue();
}

//总菜单
void nemu()
{
    AQ=(AQueue*)malloc(sizeof(AQueue));
    LQ=(LQueue*)malloc(sizeof(LQueue));
    int a;
    Output_Table(1);

    goto_xy(11,8);
    printf("1.顺序队列");
    goto_xy(31,8);
    printf("2.链式队列");
    goto_xy(51,8);
    printf("3.退出");
    goto_xy(25,10);
    printf("请选择队列类型：");
    scanf("%d",&a);
    while((a!=1) && (a!=2) && (a!=3))
    {
        goto_xy(40,11);
        printf("                           ");
        goto_xy(30,11);
        printf("输入错误，请重新输入：");
        scanf("%d",&a);
    }
    system("cls");
    if(a == 1)
        nemuAQueue();
    if(a == 2)
        nemuLQueue();
    if(a == 3)
        exit(0);
}


