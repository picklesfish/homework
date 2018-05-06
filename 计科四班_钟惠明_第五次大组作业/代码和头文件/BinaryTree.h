/****************************************************************************************
    File Name               :BinaryTree.h
    Author                  :ZhongHuiMing
    Create Date             :2018/5/5
*****************************************************************************************/

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef BINARYTREE_H_INCLUDE
#define BINARYTREE_H_INCLUDE

/******************************************************
*   Include File Section
******************************************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

/******************************************************
*   Struct Define Section
******************************************************/
//表达式用链表存储，数字和字符用共用体存储
union number
{
    int data;
    char ch;
};

//表达式
typedef struct expression
{
    union number data;
    int flag;                  //1表示data为数字，2表示为字符
    struct expression *next;
}Expression;



//顺序存储的二叉树
typedef struct
{
    union number *elem;             //0号单元闲置
    int lastIndex;                  // 二叉树最后一个结点的编号
}SqBiTree;


//链式存储的二叉树
typedef struct  BiTNode
{
    union number data;                  // 数据域
    int flag;                           //用来表示数据域的类型
    int num;                //用来表示孩子的赋值个数
    struct BiTNode  *lchild,*rchild;    // 左、右孩子指针
}BiTNode,*BiTree;                      // 二叉链表

typedef enum Status
{
	ERROR,
	SUCCESS
}Status;
/**********************************************************
*   End-Multi-Include-Prevent Section
***********************************************************/
#endif // BINARYTREE_H

/***************表达式*************/
//输入表达式,将表达式存储到形参head的链表中去
void input_Expression(Expression *head);

//输出表达式，将形参head表示的链表里的表达式输出
void output_Expression(Expression *head);

//检查表达式
Status check_Expression(Expression *head);

//检查括号匹配
Status check_Bracket(Expression *head);

//将链表逆转
//使用的所有链表头节点都是不放数据的
Expression *backspin(Expression *head);

//将中缀表达式转换成前缀表达式
Expression *transform(Expression *head);

/*********二叉树**********/
//初始化构造空二叉树
Status initBiTree(BiTree T);

//摧毁二叉树
Status DestroyBiTree(BiTree T);

//根据前缀表达式defintion和先序非递归遍历来实现
Status createTree(BiTree root,Expression* defintion);


Status PreOrderTraverse(BiTree T);     //先序遍历

Status InOrderTraverse(BiTree T);	    //中序遍历

Status PostOrderTraverse(BiTree T);	    //后序遍历

Status LevelOrderTraverse(BiTree T);    //层序遍历

//构造出的二叉树求值,使用先序非递归遍历
int Value(BiTNode T);


//控制光标函数，使光标跳转到（X，Y）坐标上
void goto_xy(int x,int y);

//输出窗口函数
void output_Window();

//菜单
void menu();












