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

void merge(dataType *s,long int left,long int right);

void merge_sort(dataType *s,long int left,long int right);

long sort(dataType *s,long int low,long int high);

void QSort_Recursion(dataType *s,long int first,long int last);

void QSort(dataType *s,long n);

void InsertSort(dataType *s,long int n);

void CountSort(dataType *s,long n);

/*********************测试输出*****************************/
void writedata();

/*********大数据测试*********/
void InsertSortTest(long n);

void MergeSortTest(long n);

void QSortTest(long n);

void QSortRecursionTest(long n);

void CountSortTest(long n);

void RadixCountSortTest(long n);

/**********小数据测试*********/
void InsertTest(dataType *ch);

void mergeTest(dataType *ch);

void QSort_Test(dataType *ch);

void QSort_R_Test(dataType *ch);

void CountTest(dataType *ch);

void RadixTest(dataType *ch);

/***********菜单***********/
void bigDataTest(int a);

void numberTest();

void menu();

void goto_xy(int x,int y);

void Output_Table();
