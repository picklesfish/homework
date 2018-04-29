#include"sort.h"
#include<math.h>

/*************插入排序****************/
void InsertSort(dataType *s,long int n)
{
    int i,j;
    dataType temp;
    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=s[i];
        while(j>=0)
        {
            if(s[j]>temp)
            {
                s[j+1]=s[j];
                j--;
            }
            else
                break;
        }
        s[j+1]=temp;
    }
}

/***********合并排序*************/
void merge(dataType *s,long int left,long int right)
{
    int mid,M,*p;
    int i,j,k=0;
    M=right-left;
    p=(int *)malloc(sizeof(int)*(M+1));
    mid=(left+right)/2;
    i=left,j=mid+1;
    while(i<=mid&&j<=right)
    {
        if(s[i]<=s[j])          /**当两个数的值相同时**/
            p[k++]=s[i++];
        else
            p[k++]=s[j++];
    }
    while(i<=mid)                  /**将后面没比较到的数加上去**/
        p[k++]=s[i++];
    while(j<=right)
        p[k++]=s[j++];
    for(i=0;left<=right;i++)
        s[left++]=p[i];
    free(p);
}

void merge_sort(dataType *s,long int left,long int right)
{
    int mid;
    if(left<right)
    {
        mid=(right+left)/2;
        merge_sort(s,left,mid);
        merge_sort(s,(mid+1),right);
        merge(s,left,right);
    }
}


/**********快速排序递归版***************/
long sort(dataType *s,long int low,long int high)
{
    int temp;
    temp=s[low];
    while(high>low)
    {
        while(high>low&&s[high]>=temp)                  /***大于等于号是为了将相同的值也进行排序***/
            high--;
        if(s[high]<temp)                                /***不能有等号是因为有等号会在只有两个数排序而又不满足条件的时候将他们交换***/
            s[low++]=s[high];
        while(low<high&&s[low]<=temp)
            low++;
        if(s[low]>temp)
            s[high--]=s[low];
    }
    s[low]=temp;
    return low;
}

void QSort_Recursion(dataType *s,long int first,long int last)
{
    int pos;
    if(first<last)
    {
        pos=sort(s,first,last);
        QSort_Recursion(s,first,(pos-1));
        QSort_Recursion(s,(pos+1),last);
    }
}

/**********非递归版*******************/
void QSort(dataType *s,long n)
{
    long temp;
    int *stack;
    stack=(int*)malloc(sizeof(int)*(n/2));
    int top=0;
    stack[top++]=0;
    stack[top++]=n-1;
    int left,right;
    int hight,low;
    while(top>0)
    {
        right=stack[--top];
        left=stack[--top];
        hight=right;        //记录当前的始末位置
        low=left;

        temp=s[left];
        while(right > left)
        {
            while((right > left)&&(s[right]>=temp))                  /***大于等于号是为了将相同的值也进行排序***/
                right--;
            if(s[right]<temp)                                /***不能有等号是因为有等号会在只有两个数排序而又不满足条件的时候将他们交换***/
                s[left++]=s[right];
            while((left<right)&&(s[left]<=temp))
                left++;
            if(s[left]>temp)
                s[right--]=s[left];
        }
        s[left]=temp;

        if((left-low) >=2)
        {
            stack[top++]=low;
            stack[top++]=left-1;
        }
        if((hight-left) >=2)
        {
            stack[top++]=left+1;
            stack[top++]=hight;
        }
    }
    free(stack);
}

/***********计数排序******************/
void CountSort(dataType *s,long n)
{
    long i,j,max;
    max=s[0];
    for(i=1;i<n;i++)
    {
        if(s[i]>max)
            max=s[i];
    }
    for(i=0;i<max;i++)      //数组初始化为0；
        ch1[i]=0;

    for(i=0;i<n;i++)        //计算每种数的个数
        ch1[s[i]]++;

    for(i=1;i<max;i++)      //计算小于等于该数的个数
        ch1[i]=ch1[i]+ch1[i-1];

    for(i=n-1;i>=0;i--)
    {
        j=s[i];
        ch2[--ch1[j]]=s[i];
    }

    for(i=0;i<n;i++)
        s[i]=ch2[i];
}

/***********基数计数排序****************/
//计算数组s里面最大数的位数
int countNum(dataType *s,long n)
{
    long i,max;
    max=s[0];
    for(i=1;i<n;i++)
    {
        if(s[i]>max)
            max=s[i];
    }
    i=0;
    while(max!=0)
    {
        i++;
        max/=10;
    }
    return i;
}

//求一个数Num的第N位数(从个位数开始算)
int placesNum(dataType num,int N)
{
    dataType k=1;
    int i,m;
    for(i=1;i<N;i++)
        k*=10;
    if(k>num)
        return 0;
    m=(num/k)%10;
    return m;
}

//基数排序
void RadixCountSort(dataType *s,long n)
{
    int num,temp;
    long i,j;
    int ch3[10]={0};

    num=countNum(s,n);          //最大数的位数

    for(i=1;i<=num;i++)
    {
        for(j=0;j<n;j++)            //收集
        {
            temp=placesNum(s[j],i);       //s[j]的第i位数的数值
            ch3[temp]++;
        }

        for(j=1;j<10;j++)           //统计
            ch3[j]=ch3[j]+ch3[j-1];

        for(j=n-1;j>=0;j--)         //分配
        {
            temp=placesNum(s[j],i);
            ch3[temp]--;
            ch2[ch3[temp]]=s[j];
        }
        for(j=0;j<10;j++)           //清零
            ch3[j]=0;

        for(j=0;j<n;j++)
            s[j]=ch2[j];
    }
}




