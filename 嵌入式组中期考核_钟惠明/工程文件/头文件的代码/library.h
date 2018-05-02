/****************************************************************************************
    File Name               :library.h
    Author                  :ZhongHuiMing
    Create Date             :2018/4/27
*****************************************************************************************/

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LIBRARY_H_INCLUDE
#define LIBRARY_H_INCLUDE

/******************************************************
*   Include File Section
******************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/******************************************************
*   Struct Define Section
******************************************************/

/**********存放书籍*************/
 //每本书的结构体
typedef struct book
{
    char num[7];            //编号,每本书的编号前两位为类型排位，后四位为该书在该类型中的排位
    char name[20];          //书名
    char author[20];        //作者
    char kind;              //书的类型，这里定义书的类型为A,B,C....
    int nowStock;           //现存量
    int sumStock;           //总库存量
    struct book *next;
}Book;

//图书存放系统结构体，用于存放书籍的分类和指向他们的指针
typedef struct library
{
    char book_Kind;
    Book *bookHead;
    struct library *next;
}Library;

typedef enum
{
    false,
    ture
}Status;

/**********存放借阅记录************/
//借阅的书
typedef struct borrow
{
    Book *book;              //指向书的信息
    char bookName[20];       //书名
    char date[10];           //借阅日期
    char returndate[10];     //最迟还书日期
    struct borrow *next;
}Borrow;

//学生借书记录
typedef struct borrowRecord
{
    char studentNumber[10];
    char studentName[20];
    int overdueTime;          //逾期归还的次数，超过十次将拉入黑名单
    int bookNum;              //当前借书总量，超过十本将不能借书
    Borrow *bookHead;         //借的书
    struct borrowRecord *next;
}BorrowRecord;

/******黑名单记录*************/
typedef struct blacklist
{
    char studentNumber[10];
    char studentName[20];
    int overdueTime;
    struct blacklist *next;
}BlackList;

/**********************************************************
*   End-Multi-Include-Prevent Section
***********************************************************/
#endif

//全局变量
Library *Lib;               //存放图书的入口
BorrowRecord *Record;       //借阅记录的总入口
BlackList *Black;           //黑名单记录链表头指针
int M,N;                    //图书入库时用于记录编号


/********入库**********/
//将数字编号转换成字符串
void transform(int m,int n,char *num);

//寻找分类，返回指向该分类的第一本书的指针
Book *searchKind(char kind);

//将某本书放入库中
void inLibrary(Book *p,int n);

//图书入库
void input();

/********清除************/
//清除库存
Status destroyBook();

/*********借阅**********/
//从借书记录里寻找该学生，若未找到则新增结点，返回指向该学生的指针
BorrowRecord *searchStudent(char *studentNum);

//根据书名查找该书
Book *searchBook(char *name);

//将日期增加一个月,用于推算最迟还书日期
void addDate(char *date,char *returndate);

//借阅
void borrow();

/*********归还*********/
//从借书记录里寻找该学生，返回指向该学生的指针，若未找到则返回NULL
BorrowRecord *searchRecordStudent(char *studentNum);

//将学生加入黑名单
void addBlacklist(BorrowRecord *R);

//归还
void giveBack();

/**********查看*************/
//管理员查看所有借书记录
void ViewRecord();

//学生查看自己的借阅情况
void ViewSelf();

//显示所有图书
void outputAllBook();

//查看黑名单
void LookBlackList();

/**********菜单*************/
//欢迎输出界面
void welcome();

//管理员菜单
void AdministratorMenu();

//用户菜单
void StudentMenu();

//主菜单
void menu();

/**********其他**********/
//控制光标移动
void goto_xy(int x,int y);



