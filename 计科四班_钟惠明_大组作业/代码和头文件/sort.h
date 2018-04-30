/*******************************************************************************************
*   File Name               :           sort.h
*   SYSTEM                  :           win10
*   create Data             :           2018.4.29
*
*******************************************************************************************/
/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef SORT_H_INCLUDE
#define SORT_H_INCLUDE

/******************************************************
*   Include File Section
******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*******************************************************
*   Macro Define Section
*******************************************************/
#define dataType long
dataType s[200000];
dataType ch1[200000];
dataType ch2[200000];

/**********************************************************
*   End-Multi-Include-Prevent Section
***********************************************************/
#endif // SORT_H_INCLUDE

/***********************排序********************************/

/*********合并排序**********/
void merge(dataType *s,long int left,long int right);

void merge_sort(dataType *s,long int left,long int right);

/*********快排非递归***********/
long sort(dataType *s,long int low,long int high);

/************快排递归***********/
void QSort_Recursion(dataType *s,long int first,long int last);

void QSort(dataType *s,long n);

/*********插入***********/
void InsertSort(dataType *s,long int n);

/**********计数***********/
void CountSort(dataType *s,long n);

/***********基数**************/
//计算数组s里面最大数的位数
int countNum(dataType *s,long n);

//求一个数Num的第N位数(从个位数开始算)
int placesNum(dataType num,int N);

void RadixCountSortTest(long n);

/*********************测试输出*****************************/
//将数据写到文件中去
void writedata();

/*********大数据测试*********/
void InsertSortTest(long n);

void MergeSortTest(long n);

void QSortTest(long n);

void QSortRecursionTest(long n);

void CountSortTest(long n);

void RadixCountSortTest(long n);

/**********小数据测试*********/
void InsertTest();

void mergeTest();

void QSort_Test();

void QSort_R_Test();

void CountTest();

void RadixTest();

/***********菜单***********/
//大数据量测试
void bigDataTest(int a);

//大量小数据测试
void numberTest();

void menu();

void goto_xy(int x,int y);

void Output_Table();
