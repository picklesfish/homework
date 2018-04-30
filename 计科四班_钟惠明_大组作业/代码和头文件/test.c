#include"sort.h"
#include<windows.h>
#include<time.h>
#include<unistd.h>

//将数据写进文件中
void writedata()
{
    FILE *f1=fopen("testdata1.txt","w");
    if(f1 == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }
    long int i;
    srand(time(NULL));
    for(i=0;i<10000;i++)
    {
        s[i]=rand()%100000;
        fprintf(f1,"%ld\t",s[i]);
    }
    fclose(f1);

    FILE *f2=fopen("testdata2.txt","w");
    if(f2 == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }
    for(i=0;i<50000;i++)
    {
        s[i]=rand()%100000;
        fprintf(f2,"%ld\t",s[i]);
    }
    fclose(f2);

    FILE *f3=fopen("testdata3.txt","w");
    if(f3 == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }
    for(i=0;i<200000;i++)
    {
        s[i]=rand()%100000;
        fprintf(f3,"%ld\t",s[i]);
    }
    fclose(f3);
}

/***************大数据测试********************/
void InsertSortTest(long n)
{
    FILE *f;
    long i;
    switch(n)
    {
        case 10000: f=fopen("testdata1.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<10000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 50000: f=fopen("testdata2.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<50000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 200000:f=fopen("testdata3.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<200000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;
    }
    clock_t start = clock();
    InsertSort(s,n);
    clock_t end = clock() - start;
    goto_xy(24,12);
    printf("%dus",end);
}

void MergeSortTest(long n)
{
    FILE *f;
    long i;
    switch(n)
    {
        case 10000: f=fopen("testdata1.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<10000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 50000: f=fopen("testdata2.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<50000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 200000:f=fopen("testdata3.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<200000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;
    }
    clock_t start = clock();
    merge_sort(s,0,n);
    clock_t end = clock() - start;
    goto_xy(37,12);
    printf("%dus",end);
}

void QSortTest(long n)
{
    FILE *f;
    long i;
    switch(n)
    {
        case 10000: f=fopen("testdata1.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<10000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 50000: f=fopen("testdata2.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<50000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 200000:f=fopen("testdata3.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<200000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;
    }
    clock_t start = clock();
    QSort(s,n);
    clock_t end = clock() - start;
    goto_xy(50,12);
    printf("%dus",end);
}

void QSortRecursionTest(long n)
{
    FILE *f;
    long i;
    switch(n)
    {
        case 10000: f=fopen("testdata1.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<10000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 50000: f=fopen("testdata2.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<50000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 200000:f=fopen("testdata3.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<200000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;
    }
    clock_t start = clock();
    QSort_Recursion(s,0,n);
    clock_t end = clock() - start;
    goto_xy(63,12);
    printf("%dus",end);
}

void CountSortTest(long n)
{
    FILE *f;
    long i;
    switch(n)
    {
        case 10000: f=fopen("testdata1.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<10000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 50000: f=fopen("testdata2.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<50000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 200000:f=fopen("testdata3.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<200000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;
    }
    clock_t start = clock();
    CountSort(s,n);
    clock_t end = clock() - start;
    goto_xy(76,12);
    printf("%dus",end);
}

void RadixCountSortTest(long n)
{
    FILE *f;
    long i;
    switch(n)
    {
        case 10000: f=fopen("testdata1.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<10000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 50000: f=fopen("testdata2.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<50000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;

        case 200000:f=fopen("testdata3.txt","r");
                    if(f == NULL)
                    {
                        printf("can't open the file");
                        Sleep(1000);
                        exit(0);
                    }
                    for(i=0;i<200000;i++)
                        fscanf(f,"%ld",&s[i]);
                    fclose(f);
                    break;
    }
    clock_t start = clock();
    RadixCountSort(s,n);
    clock_t end = clock() - start;
    goto_xy(89,12);
    printf("%dus",end);
}

/****************小数据测试*******************/
void InsertTest()
{
    dataType ch[100];
    long i,temp;
    int j;
    FILE *f=fopen("小数据测试.txt","r");
    if(f == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }

    clock_t start = clock();
    for(i=0;i<200000;i++)
    {
        fscanf(f,"\n%ld\n",&temp);
        for(j=0;j<100;j++)
            fscanf(f,"%ld\t",&ch[j]);
        InsertSort(ch,100);
    }
    clock_t end = clock() - start;
    fclose(f);
    goto_xy(24,12);
    printf("%dus",end);
}

void mergeTest()
{
    dataType ch[100];
    long i,temp;
    int j;
    FILE *f=fopen("小数据测试.txt","r");
    if(f == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }

    clock_t start = clock();
    for(i=0;i<200000;i++)
    {
        fscanf(f,"\n%ld\n",&temp);
        for(j=0;j<100;j++)
            fscanf(f,"%ld\t",&ch[j]);
        merge_sort(ch,0,100);
    }
    clock_t end = clock() - start;
    fclose(f);
    goto_xy(37,12);
    printf("%dus",end);
}

void QSort_Test()
{
    dataType ch[100];
    long i,temp;
    int j;
    FILE *f=fopen("小数据测试.txt","r");
    if(f == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }

    clock_t start = clock();
    for(i=0;i<200000;i++)
    {
        fscanf(f,"\n%ld\n",&temp);
        for(j=0;j<100;j++)
            fscanf(f,"%ld\t",&ch[j]);
       QSort(ch,100);
    }
    clock_t end = clock() - start;
    fclose(f);
    goto_xy(50,12);
    printf("%dus",end);
}

void QSort_R_Test()
{
    dataType ch[100];
    long i,temp;
    int j;
    FILE *f=fopen("小数据测试.txt","r");
    if(f == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }

    clock_t start = clock();
    for(i=0;i<200000;i++)
    {
        fscanf(f,"\n%ld\n",&temp);
        for(j=0;j<100;j++)
            fscanf(f,"%ld\t",&ch[j]);
        QSort_Recursion(ch,0,100);
    }
    clock_t end = clock() - start;
    fclose(f);
    goto_xy(63,12);
    printf("%dus",end);
}

void CountTest()
{
    dataType ch[100];
    long i,temp;
    int j;
    FILE *f=fopen("小数据测试.txt","r");
    if(f == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }

    clock_t start = clock();
    for(i=0;i<200000;i++)
    {
        fscanf(f,"\n%ld\n",&temp);
        for(j=0;j<100;j++)
            fscanf(f,"%ld\t",&ch[j]);
        CountSort(ch,100);
    }
    clock_t end = clock() - start;
    fclose(f);
    goto_xy(76,12);
    printf("%dus",end);
}

void RadixTest()
{
    dataType ch[100];
    long i,temp;
    int j;
    FILE *f=fopen("小数据测试.txt","r");
    if(f == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }

    clock_t start = clock();
    for(i=0;i<200000;i++)
    {
        fscanf(f,"\n%ld\n",&temp);
        for(j=0;j<100;j++)
            fscanf(f,"%ld\t",&ch[j]);
        RadixCountSort(ch,100);
    }
    clock_t end = clock() - start;
    fclose(f);
    goto_xy(89,12);
    printf("%dus",end);
}

/****************菜单********************/
void menu()
{
    int i,a,b;
    goto_xy(20,14);
    printf("请选择测试类型：(1.大数据量测试  2.大量小数据测试)");
    scanf("%d",&a);
    getchar();
    while((a!=1) && (a!=2))
    {
        goto_xy(20,15);
        printf("                   ");
        goto_xy(20,15);
        printf("请重新输入1或者2) ");
        scanf("%d",&a);
        getchar();
    }
    system("cls");
    if(a == 1)
    {
        goto_xy(20,15);
        printf("请选择测试数量级（1.10000  2.50000  3.200000 ");
        goto_xy(20,16);
        printf("请输入数量级前的数字：");
        scanf("%d",&b);
        getchar();
        while((b!=1)&&(b!=2)&&(b!=3))
        {
            goto_xy(20,22);
            printf("输入错误，请重新输入：");
            scanf("%d",&b);
            getchar();
        }
        bigDataTest(b);
    }
    if(a == 2)
        numberTest();

    system("cls");
    char ch;
    goto_xy(30,15);
    printf("继续测试？(Y/N)");
    ch=getchar();
    getchar();
    while((ch!='Y') && (ch!='N') && (ch!='y') && (ch!='n'))
    {
        goto_xy(30,16);
        printf("请选择Y或N ：");
        ch=getchar();
        getchar();
    }
    if((ch == 'N') || (ch == 'n'))
        exit(0);
    system("cls");
    menu();
}

//大量小数据测试
void numberTest()
{
    long i;
    int j;
    FILE *f1=fopen("小数据测试.txt","w");
    if(f1 == NULL)
    {
        printf("can't open the file");
        Sleep(1000);
        exit(0);
    }
    dataType *ch[100];
    srand(time(NULL));
    for(i=0;i<100000;i++)
    {
        fprintf(f1,"\n%ld\n",i);
        for(j=0;j<100;j++)
        {
            ch[j]=rand()%1000;
            fprintf(f1,"%ld\t",ch[j]);
        }
    }
    fclose(f1);
    Output_Table();
    for(i=0;i<6;i++)
    {
        goto_xy(24+13*i,10);
        printf("100");
    }
    goto_xy(20,18);
    printf("请稍等。。。");

    InsertTest();
    mergeTest();
    QSort_Test();
    QSort_R_Test();
    CountTest();
    RadixTest();

    goto_xy(20,18);
    printf("                 ");
    getchar();
    system("cls");
}

//大数据量测试
void bigDataTest(int a)
{
    long m,i;
    switch(a)
    {
        case 1: m=10000;
                break;

        case 2: m=50000;
                break;

        case 3: m=200000;
                break;
    }
    Output_Table();
    for(i=0;i<6;i++)
    {
        goto_xy(24+13*i,10);
        printf("%ld",m);
    }

    goto_xy(20,18);
    printf("请稍等。。。");
    InsertSortTest(m);
    MergeSortTest(m);
    QSortTest(m);
    QSortRecursionTest(m);
    CountSortTest(m);
    RadixCountSortTest(m);

    //将排序后数据放到文件中
    FILE *f=fopen("大数据排序后.txt","w");
    if(f == NULL)
    {
        printf("can open this file");
        Sleep(500);
        exit(0);
    }
    for(i=0;i<m;i++)
    {
        fprintf(f,"%ld\t",s[i]);
        if(i%50 == 0)
            fprintf(f,"\n");
    }
    fclose(f);

    goto_xy(20,18);
    printf("                 ");
    getchar();
    system("cls");
}

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

//输出表格
void Output_Table()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        goto_xy(10,7+i*2);
        printf("-------------------------------------------------------------------------------------------");
        for(j=0;j<8;j++)
        {
            goto_xy(10+13*j,8+i*2);
            printf("|");
        }
    }
    goto_xy(10,7+i*2);
    printf("--------------------------------------------------------------------------------------------");

    goto_xy(11,8);
    printf("排序方式");
    goto_xy(24,8);
    printf("插入");
    goto_xy(37,8);
    printf("归并");
    goto_xy(50,8);
    printf("快排");
    goto_xy(63,8);
    printf("快排（递归）");
    goto_xy(76,8);
    printf("计数");
    goto_xy(89,8);
    printf("基数");

    goto_xy(11,10);
    printf("数据量级");
    goto_xy(11,12);
    printf("用时");
}



