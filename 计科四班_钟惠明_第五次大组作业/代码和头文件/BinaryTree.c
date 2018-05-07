#include"BinaryTree.h"
#include<windows.h>

/*********创建二叉树**********/
//初始化构造空二叉树
Status initBiTree(BiTree T)
{
    T=(BiTree)malloc(sizeof(BiTNode));
    T->data.ch='#';
    T->num=0;
    T->flag=2;
    T->rchild=NULL;
}

//摧毁二叉树
Status DestroyBiTree(BiTree T)
{
    if(T->lchild !=NULL)
        DestroyBiTree(T->lchild);
    if(T->rchild !=NULL)
        DestroyBiTree(T->rchild);
    free(T);
}

//根据表达式创建二叉树
//根据前缀表达式defintion和先序非递归遍历来实现
Status createTree(BiTree root,Expression* defintion)
{
    if(defintion == NULL)
        return ERROR;

    Expression *p;
    p=defintion->next;

    BiTree Stack[MAX];      //建立栈
    int top=0;

    BiTree T1,T2;
    T1=(BiTree)malloc(sizeof(BiTNode));
    T1->lchild=NULL;
    T1->rchild=NULL;
    T1->num=0;
    root->lchild=T1;

    if(p->flag == 1)                    //存放根数据
        T1->data.data=p->data.data;
    else
        T1->data.ch=p->data.ch;
    T1->flag = p->flag;
    p=p->next;

    Stack[top++]=T1;
    while((top>0) && (p!=NULL))
    {
        T1=Stack[--top];
        if(T1->flag == 1)            //结点存放的是数字，则是叶子结点
        {
            T1->lchild=NULL;
            T1->rchild=NULL;
            T1->num=2;
            continue;
        }

        T2=(BiTree)malloc(sizeof(BiTNode));      //非叶子结点则要创建子树
        T2->lchild=NULL;
        T2->rchild=NULL;
        if(p->flag == 1)
            T2->data.data=p->data.data;
        else
            T2->data.ch=p->data.ch;

        T2->flag=p->flag;
        T2->num=0;
        p=p->next;

        if(T1->num == 0)          //0表示左右孩子都未赋值，先赋值给左孩子
            T1->lchild=T2;
        if(T1->num == 1)          // 1表示左孩子已经赋值，此时赋值给右孩子；
            T1->rchild=T2;
        (T1->num)++;

        if((T1->num)<2)            //孩子为赋值完，再次入栈
            Stack[top++]=T1;

        Stack[top++]=T2;
    }
    return SUCCESS;
}

//遍历
Status PreOrderTraverse(BiTree T)     //先序遍历
{
    if(T!=NULL)
    {
        if(T->flag == 1)
            printf("%d",T->data.data);
        if(T->flag == 2)
            printf("%c",T->data.ch);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

Status InOrderTraverse(BiTree T)	    //中序遍历
{
    if(T!=NULL)
    {
        InOrderTraverse(T->lchild);
        if(T->flag == 1)
            printf("%d",T->data.data);
        if(T->flag == 2)
            printf("%c",T->data.ch);
        InOrderTraverse(T->rchild);
    }
}

Status PostOrderTraverse(BiTree T)	//后序遍历
{
     if(T!=NULL)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        if(T->flag == 1)
            printf("%d",T->data.data);
        if(T->flag == 2)
            printf("%c",T->data.ch);
    }
}

Status LevelOrderTraverse(BiTree T)	//层序遍历
{
    //创建队列
    BiTree queue[MAX];
    BiTree p;
    int first=0,end=0;
    queue[end++]=T;
    while(first!=end)
    {
        p=queue[++first];
        if(p->flag == 1)
            printf("%d",p->data.data);
        if(p->flag == 2)
            printf("%c",p->data.ch);
        if(p->lchild !=NULL)
            queue[end++]=p->lchild;
        if(p->rchild !=NULL)
            queue[end++]=p->rchild;
    }
}

//构造出的二叉树求值,使用先序非递归遍历
int Value(BiTNode T)
{
    int result;     //用来放运算结果
    char ch;        //用来放运算符
    BiTree stack[MAX];
    int top=0;
    BiTree p,L,R;
    p=T.lchild;        //初始化的时候第一个根没有数据，只有左孩子，
    stack[top++]=p;

    while(top>0)
    {
        p=stack[--top];
        if(p->flag == 1)
            continue;
        if(p->flag == 2)        //结点数据为字符，则左右孩子一定存在
        {
            L=p->lchild;
            R=p->rchild;
            if((L->flag == 1) && (R->flag == 1))      //左右孩子都为数字，则进行计算
            {
                switch(p->data.ch)
                {
                    case '+':   result=(L->data.data) + (R->data.data);
                                break;
                    case '-':   result=(L->data.data) - (R->data.data);
                                break;
                    case '*':   result=(L->data.data)*(R->data.data);
                                break;
                    case '/':   result=(L->data.data)/(R->data.data);
                                break;
                }
                p->data.data=result;
                p->flag=1;
            }
            else
            {
                stack[top++]=p;         //未进行运算，则要重新入栈
                stack[top++]=R;
                stack[top++]=L;
            }
        }
    }//结束后根节点的值就是所求结果
    result=p->data.data;
    return result;
}



/*************表达式****************/
//输入表达式,将表达式存储到形参head的链表中去
void input_Expression(Expression *head)
{
    Expression *p;
    char s[100];
    int i=0,num=0;
    int w=0;
    p=(Expression*)malloc(sizeof(Expression));
    head->next=p;
    p->next=NULL;

    goto_xy(11,5);
    gets(s);
    if((s[i] == '-'))         //第一个字符为负号的时候
    {
        w=1;
        i++;
    }
    while((s[i]>='0') && (s[i]<='9'))   //操作数可能是两位数甚至更多，假设数值都比较小，计算以后也不会溢出
    {
        num=num*10+s[i++]-'0';
    }
    if(num!=0)
    {
        if(w == 1)
        {
            p->data.data=num*(-1);
            p->flag=1;
        }
        else
        {
            p->data.data=num;
            p->flag=1;
        }
    }
    else                              //第一个字符可能不是数字而是左括号，其他情况先不讨论
    {
        if(w==1)         //这时候第二个字符为左括号
        {
            p->data.data=0;         //括号前负号相当于前面有个0
            p->flag=1;
            p=p->next=(Expression*)malloc(sizeof(Expression));
            p->data.ch='-';
            p->flag=2;
            p=p->next=(Expression*)malloc(sizeof(Expression));
        }
        p->data.ch=s[i++];          //无论前面有没有负号这里都有个左括号
        p->flag=2;
    }
    while(s[i]!='\0')
    {
        num=0;
        p=p->next=(Expression*)malloc(sizeof(Expression));
        while((s[i]>='0') && (s[i]<='9'))
        {
            num=num*10+s[i++]-'0';
        }
        if(num!=0)
        {
            p->data.data=num;
            p->flag=1;
        }
        else
        {
            p->data.ch=s[i++];
            p->flag=2;
        }
    }
    p->next=NULL;
}

//输出表达式，将形参head表示的链表里的表达式输出
void output_Expression(Expression *head)
{
    head=head->next;
    while(head!=NULL)
    {
        if(head->flag == 1)
            printf("%d ",head->data.data);
        if((head->flag == 2) && (head->data.ch!='#'))
            printf("%c ",head->data.ch);
        head=head->next;
    }
}

//检查表达式
Status check_Expression(Expression *head)
{
    Expression *p1,*p2;
    p1=head;
    p1=p1->next;
    int n=0;
    while(p1)
    {
        p2=p1->next;
        if(p1->flag == 2)
            n++;
        if((p2!=NULL) && (p1->flag == 2) && p2->flag == 2)
        {
            if((p1->data.ch!='(') && (p1->data.ch!=')'))
                if((p2->data.ch!='(') && (p2->data.ch!=')'))            //两个操作符连续又不包含括号的的话则错误
                    return ERROR;
        }
        p1=p2;
    }
    if(n=0)
        return ERROR;
    return SUCCESS;
}

//检查括号匹配
Status check_Bracket(Expression *head)
{
    Expression *p=head->next;
    char Stack[MAX];
    int top=0;

    while(p!=NULL)
    {
        if(p->flag == 2)
        {
            if(p->data.ch == '(')
               Stack[top++]=p->data.ch;
            if(p->data.ch == ')')
            {
                if(top<=0)
                    return ERROR;
                top--;
            }
        }
        p=p->next;
    }
    if(top>0)                                 //若栈不为空，则左括号多于右括号
        return ERROR;
    else
        return SUCCESS;
}


//将链表逆转
//使用的所有链表头节点都是不放数据的
Expression *backspin(Expression *head)
{
    if(head == NULL)
        return NULL;
    Expression *p1,*p2,*p3;
    p1=head->next;
    p2=p1->next;
    p1->next=NULL;
    while(p2!=NULL)
    {
        p3=p2->next;
        p2->next=p1;
        if(p3 == NULL)
            break;
        p1=p2;
        p2=p3;
    }//此时p2为头节点
    p3=(Expression*)malloc(sizeof(Expression));
    p3->next=p2;
    return p3;
}

//将中缀表达式转换成前缀表达式
Expression *transform(Expression *head)
{
    if(head == NULL)
        return NULL;
    Expression *p,*preHead;
    p=(Expression*)malloc(sizeof(Expression));          //放后缀表达式
    p->next=NULL;
    preHead=p;
    head=head->next;

    char Stack[MAX];            //用来存放字符的栈
    int top=0;

    char ch1,ch2;

    while(head!=NULL)
    {
        if(head->flag == 1)             //存放的是数字
        {
            p=p->next=(Expression*)malloc(sizeof(Expression));
            p->data.data=head->data.data;
            p->flag=head->flag;
        }
        if(head->flag == 2)             //存放的是字符
        {
            ch1=head->data.ch;
            ch2=Stack[top-1];
            switch(ch1)
            {
                case ')':   Stack[top++]=ch1;                       //直接入栈
                            break;
                case '(':   while((ch2=Stack[--top])!=')')          //将括号里的都输出
                            {
                                p=p->next=(Expression*)malloc(sizeof(Expression));
                                p->data.ch=ch2;
                                p->flag=head->flag;
                            }
                            break;
                case '+':
                case '-':   if((ch2 == '*') || (ch2 == '/'))        //优先级小于栈顶元素则直接输出栈顶元素
                            {
                                while((ch2 == '*') || (ch2 == '/'))
                                {
                                    p=p->next=(Expression*)malloc(sizeof(Expression));
                                    p->data.ch=ch2;
                                    p->flag=head->flag;
                                    top--;
                                    ch2=Stack[top-1];
                                    if(ch2 == ')')              //遇到括号ch1直接入栈
                                        break;
                                }
                            }
                            Stack[top++]=ch1;                   //无论如何ch1最终都要入栈
                            break;

                case '*':
                case '/':   Stack[top++]=ch1;               //直接入栈
                            break;
            }//switch
        }//if
        head=head->next;
    }//while
    while(top!=0)
    {
        p=p->next=(Expression*)malloc(sizeof(Expression));
        p->data.ch=Stack[--top];
        p->flag=2;
    }
    p->next=NULL;
    return preHead;
}


/*********窗口************/
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

//输出窗口函数
void output_Window()
{
    int i;
    goto_xy(10,3);
    printf("____________________________________________________________");
    goto_xy(10,15);
    printf("____________________________________________________________");
    goto_xy(10,22);
    printf("____________________________________________________________");
    for(i=4;i<=22;i++)
    {
        goto_xy(10,i);
        printf("$");
        goto_xy(69,i);
        printf("$");
    }
    goto_xy(30,2);
    printf("利用二叉树进行的四则运算");
    goto_xy(11,4);
    printf("请在这里输入你要计算的四则运算表达式:");
    goto_xy(11,16);
    printf("你可以使用的运算符为(英文)： +  -  *  /  (   )");
    goto_xy(13,17);
    printf("#注意#： 如果你输入其他字符，系统会将它丢弃；或者你没有");
    goto_xy(11,18);
    printf("输入有效运算符的话，运算结果可能会出错。");
    goto_xy(11,19);
    printf("运算数的范围：（-1000，1000）");
    goto_xy(11,20);
    printf("表达式输入结束后请按回车键");
}

void menu()
{
    int a=1;
    output_Window();
    Expression *head,*p1,*p2,*p3;
    head=(Expression*)malloc(sizeof(Expression));
    head->next=NULL;
    input_Expression(head);
    if((check_Bracket(head) == ERROR) || (check_Expression(head) == ERROR))     //表达式错误
    {
        goto_xy(12,12);
        printf("表达式输入错误，请重新输入！");
        Sleep(1000);
        system("cls");
        output_Window();
        goto_xy(11,11);
        printf("你刚才输入的表达式为：");
        output_Expression(head);
        goto E;                                     //使用goto语句是防止递归调用回溯后再次输出原表达式
    }

    p1=backspin(head);          //表达式反转

    p2=transform(p1);           //转为前缀表达式
    p3=backspin(p2);

    goto_xy(11,12);
    printf("前缀表达式为：");
    output_Expression(p3);

    //创建树
    BiTree root;
    root=(BiTree)malloc(sizeof(BiTNode));
    root->lchild=NULL;
    root->rchild=NULL;
    createTree(root,p3);
    int result;
    BiTNode p;
    p=*(root);
    result=Value(p);
    goto_xy(11,13);
    printf("结果：%d",result);

    goto_xy(11,21);
    printf("继续请按1，否则退出:");
    scanf("%d",&a);
    getchar();
    E:if(a == 1)
        {
            system("cls");
            menu();
        }

}





