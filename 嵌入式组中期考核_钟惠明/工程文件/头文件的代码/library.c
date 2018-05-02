#include<conio.h>
#include<windows.h>
#include"library.h"

/*********入库************/
//将数字编号转换成字符串
void transform(int m,int n,char *num)
{
    num[0]=m/10+'0';
    num[1]=m%10+'0';
    num[2]=n/1000+'0';
    num[3]=n/100+'0';
    num[4]=n/10+'0';
    num[5]=n%10+'0';
    num[6]='\0';
}

//寻找分类，返回指向该分类的第一本书的指针
Book *searchKind(char kind)
{
    Library *q1,*q2;
    q1=(Library*)malloc(sizeof(Library));
    q2=(Library*)malloc(sizeof(Library));
    q1->next=NULL;
    q2->next=NULL;

    Book *BookHead;
    BookHead=(Book*)malloc(sizeof(Book));
    BookHead->next=NULL;

    int w=1;
    M=1;
    q1=Lib;           //寻找该分类
    q2=q1->next;
    while(q2!=NULL)
    {
        if(q2->book_Kind == kind)
        {
            BookHead=q2->bookHead;
            w=0;
            break;
        }
        q1=q2;
        q2=q1->next;
        M++;
    }
    if(w!=0)                   //没找到该分类,此时q1指向最后一类书籍
    {
        q2=(Library*)malloc(sizeof(Library));   //新增加图书类型
        q2->next=NULL;
        q2->book_Kind=kind;
        q1->next=q2;
        q2->bookHead=BookHead;                  //BookHead指向该类书籍的第一本
    }
    //无论找到与否，q2都指向那类书籍，BookHead都指向给类的第一本
    return BookHead;
}

//将书放入库中
void inLibrary(Book *p,int n)
{
    Book *p1,*p2;
    p1=(Book*)malloc(sizeof(Book));
    p2=(Book*)malloc(sizeof(Book));
    p1->next=NULL;
    p2->next=NULL;

    p1=searchKind(p->kind); //先找到该类书

    p2=p1->next;
    int w=1;
    N=1;
    while(p2!=NULL)         //遍历该类书籍,查找这本书是否已经存在
    {
        if(strcmp(p2->name,p->name) == 0)   //该书之前已经有了，则库存直接加1
        {
            w=0;
            p2->nowStock=p2->nowStock+n;
            p2->sumStock=p2->sumStock+n;
            free(p);
            break;
        }
        p1=p2;
        p2=p1->next;
        N++;
    }
    if(w!=0)            //该书之前不存在。此时p1指向这类书的最后一本
    {
        p->nowStock=n;
        p->sumStock=n;
        transform(M,N,p->num);
        p1->next=p;
    }
}

//图书入库
void input()
{
    system("cls");
    welcome();

    char kind;
    goto_xy(20,10);
    printf("请选择该书的类型(A,B,C...)：");
    kind=getchar();
    getchar();
    while((kind<'A') || (kind>'Z'))
    {
        goto_xy(20,10);
        printf("                                              ");
        goto_xy(20,10);
        printf("请输入正确的书籍类型：(A,B...Z):");
        kind=getchar();
        getchar();
    }

    Book *p;
      p=(Book*)malloc(sizeof(Book));
      p->next=NULL;
      p->kind=kind;

    goto_xy(20,11);
    printf("请输入书名:");
    gets(p->name);
    while(strlen(p->name)>19)
    {
        goto_xy(20,22);
        printf("抱歉，我的存储量有限，请输入短一点的名字");
        goto_xy(20,11);
        printf("                                              ");
        goto_xy(20,11);
        printf("请重新输入：");
        gets(p->name);
        goto_xy(20,22);
        printf("                                            ");
    }
    goto_xy(20,12);
    printf("请输入作者:");
    gets(p->author);
    while(strlen(p->author)>19)
    {
        goto_xy(20,22);
        printf("抱歉，我的存储量有限，请输入短一点的名字");
        goto_xy(20,12);
        printf("                                                  ");
        goto_xy(20,12);
        printf("请重新输入：");
        gets(p->name);
        goto_xy(20,22);
        printf("                                            ");
    }

    int n;
    goto_xy(20,13);
    printf("请输入数量：");
    scanf("%d",&n);
    getchar();

    while((n<0) || (n>100))
    {
        goto_xy(20,22);
        printf("一次只能存入1至100本书，请重试");
        goto_xy(20,13);
        printf("                          ");
        goto_xy(20,13);
        printf("请重新输入数量：");
        scanf("%d",&n);
        getchar();
    }

    inLibrary(p,n);

    goto_xy(20,15);
    printf("已入库，是否继续？(Y/N)");
    char ch;
    ch=getchar();
    getchar();
    while((ch!='Y') && (ch!='N'))
    {
        goto_xy(20,16);
        printf("                    ");
        goto_xy(20,16);
        printf("请输入Y或者N:");
        ch=getchar();
        getchar();
    }
    system("cls");
    if(ch == 'N')
        return ;
    else
        input();
}

/**********清除***********/
//清除库存
Status destroyBook()
{
    system("cls");
    welcome();

    char name[20];
    goto_xy(20,13);
    printf("请输入要清除的书名:");
    gets(name);
    while(strlen(name)>19)
    {
        goto_xy(20,22);
        printf("抱歉，我的存储量有限，请输入短一点的名字");
        goto_xy(20,13);
        printf("                                              ");
        goto_xy(20,13);
        printf("请重新输入：");
        gets(name);
        goto_xy(20,22);
        printf("                                            ");
    }
    Library *q1;
    q1=(Library*)malloc(sizeof(Library));
    q1->next=NULL;

    Book *p1,*p2;
    p1=(Book*)malloc(sizeof(Book));
    p2=(Book*)malloc(sizeof(Book));
    p1->next=NULL;
    p2->next=NULL;

    q1=Lib->next;
    int w=0;
    while(q1!=NULL)
    {
        p1=q1->bookHead;
        p2=p1->next;
        while(p2!=NULL)
        {
            if( strcmp(p2->name,name) == 0)
            {
                w=1;
                p1->next=p2->next;
                free(p2);
                goto_xy(20,15);
                printf("清除成功");
                Sleep(500);
                return ture;
            }
            p1=p2;
            p2=p1->next;
        }
        q1=q1->next;
    }
    if(w!=1)
    {
        goto_xy(20,15);
        printf("库存中没有该书");
        Sleep(500);
    }
    return false;
}

/**********借书************/
//从借书记录里寻找该学生，若未找到则新增结点，返回指向该学生的指针
BorrowRecord *searchStudent(char *studentNum)
{
    BorrowRecord *R1,*R2;
    R1=(BorrowRecord*)malloc(sizeof(BorrowRecord));
    R2=(BorrowRecord*)malloc(sizeof(BorrowRecord));
    R1->next=NULL;
    R2->next=NULL;

    Borrow *B1;
    B1=(Borrow*)malloc(sizeof(Borrow));
    B1->next=NULL;

    R1=Record;
    R2=R1->next;

    int w=1;
    while(R2!=NULL)
    {
        if(strcmp(R2->studentNumber,studentNum) == 0)
        {
            w=0;
            break;
        }
        R1=R2;
        R2=R1->next;
    }
    if(w!=0)        //该学生之前没有借书，此时R1指向借书的最后一位同学
    {
        R2=(BorrowRecord*)malloc(sizeof(BorrowRecord));
        R2->next=NULL;
        R1->next=R2;

        B1=(Borrow*)malloc(sizeof(Borrow));
        B1->next=NULL;
        R2->bookHead=B1;
        R2->overdueTime=0;
        R2->bookNum=0;
        strcpy(R2->studentNumber,studentNum);
        goto_xy(20,11);
        printf("请输入你的姓名：");
        gets(R2->studentName);
        while(strlen(R2->studentName)>19)
        {
            goto_xy(20,22);
            printf("抱歉，我的存储量有限，请输入短一点的名字");
            goto_xy(20,11);
            printf("                                              ");
            goto_xy(20,11);
            printf("请重新输入：");
            gets(R2->studentName);
            goto_xy(20,22);
            printf("                                              ");
        }
    }
    //不论他之前是否借过书，此时R2都指向该学生
    return R2;
}

//根据书名寻找该书
Book *searchBook(char *name)
{
    Library *q1;
    q1=(Library*)malloc(sizeof(Library));
    q1->next=NULL;

    Book *p1;
    p1=(Book*)malloc(sizeof(Book));

    q1=Lib->next;
    while(q1!=NULL)
    {
        p1=q1->bookHead;
        p1=p1->next;
        while(p1!=NULL)
        {
            if( strcmp(p1->name,name) == 0)
                return p1;
            p1=p1->next;
        }
        q1=q1->next;
    }
    return NULL;
}

//将日期增加一个月,用于推算最迟还书日期
void addDate(char *date,char *returndate)
{
    long long a=0;
    int i,b,c,d;

    for(i=0;i<8;i++)
    {
        a=a*10+date[i]-'0';
    }
    a+=30;
    b=a%100;        //日
    a=a/100;
    c=a%100;        //月
    d=a/100;        //年
    if(b>30)
    {
        b=b%30;
        c++;
    }
    if(c>12)
    {
        c=c%12;
        d++;
    }
    returndate[8]='\0';
    returndate[7]=b%10+'0';
    returndate[6]=b/10+'0';
    returndate[5]=c%10+'0';
    returndate[4]=c/10+'0';
    returndate[3]=d%10+'0';
    d=d/10;
    returndate[2]=d%10+'0';
    d=d/10;
    returndate[1]=d%10+'0';
    returndate[0]=d/10+'0';
}

//借阅
void borrow()
{
    BorrowRecord *R;
    R=(BorrowRecord*)malloc(sizeof(BorrowRecord));
    R->next=NULL;

    Borrow *B1,*B2;
    B1=(Borrow*)malloc(sizeof(Borrow));
    B2=(Borrow*)malloc(sizeof(Borrow));
    B1->next=NULL;
    B2->next=NULL;

    Book *p;
    p=(Book*)malloc(sizeof(Book));
    p->next=NULL;

    char studentNum[10];
    goto_xy(20,10);
    printf("请输入你的学号：");
    gets(studentNum);
    while(strlen(studentNum)!=8)
    {
        goto_xy(20,22);
        printf("请输入正确的学号");
        goto_xy(20,10);
        printf("                                  ");
        goto_xy(20,10);
        printf("请重新输入：");
        gets(studentNum);
        goto_xy(20,22);
        printf("                                    ");
    }

    R=searchStudent(studentNum);    //此时R指向借阅记录中的该学生结点

    if((R->bookNum) > 4)
    {
        goto_xy(16,22);
        printf("一个学生最多可借10本书，你的借书量已经超过十本，请先还书");
        Sleep(1000);
        return ;
    }

    B1=R->bookHead;
    B2=B1->next;
    while(B2!=NULL)
    {
        B1=B2;
        B2=B1->next;
    } //此时B1指向该学生借的最后一本书（不论是否存在）

    char name[20];
    char date[10];
    char returnDate[10];
    goto_xy(20,12);
    printf("请输入你要借的书名：");
    gets(name);
    while(strlen(name)>19)
    {
        goto_xy(20,22);
        printf("抱歉，这里并没有这样的书，请输入短一点的名字");
        goto_xy(20,12);
        printf("                                              ");
        goto_xy(20,12);
        printf("请重新输入书名：");
        gets(name);
        getchar();
        goto_xy(20,22);
        printf("                                                 ");
    }

    goto_xy(20,13);
    printf("请输入今天的日期：");
    gets(date);
    while(strlen(date)!=8)
    {
        goto_xy(20,22);
        printf("请输入正确的日期(如20180430)");
        goto_xy(20,13);
        printf("                                           ");
        goto_xy(20,13);
        printf("请重新输入日期：");
        gets(date);
        getchar();
        goto_xy(20,22);
        printf("                                          ");
    }

    p=searchBook(name);

    if(p == NULL)
    {
        goto_xy(20,18);
        printf("抱歉，未找到该书");
        Sleep(500);
        return ;
    }
    if(p->nowStock == 0)
    {
        goto_xy(20,18);
        printf("抱歉，该书已经被借完了");
        Sleep(500);
        return ;
    }

    p->nowStock--;

    B2=(Borrow*)malloc(sizeof(Borrow));
    B2->next=NULL;
    strcpy(B2->bookName,name);
    B1->next=B2;
    B2->book=p;
    addDate(date,returnDate);
    strcpy(B2->returndate,returnDate);
    strcpy(B2->date,date);
    (R->bookNum)++;
    goto_xy(20,18);
    printf("借书成功！");
    Sleep(1000);
}

/**********还书*************/
//根据从借书记录里寻找该学生，返回指向该学生的指针，若未找到则返回NULL
BorrowRecord *searchRecordStudent(char *studentNum)
{
    BorrowRecord *R1;
    R1=(BorrowRecord*)malloc(sizeof(BorrowRecord));
    R1->next=NULL;

    R1=Record;
    R1=R1->next;
    while(R1!=NULL)
    {
        if(strcmp(R1->studentNumber,studentNum) == 0)
            return R1;
        R1=R1->next;
    }
    return NULL;
}

//将学生加入黑名单
void addBlacklist(BorrowRecord *R)
{
    BlackList *p1,*p2;
    p1=(BlackList*)malloc(sizeof(BlackList));
    p2=(BlackList*)malloc(sizeof(BlackList));
    p1->next=NULL;
    p2->next=NULL;

    p1=Black;
    p2=p1->next;
    int w=1;
    while(p2!=NULL)
    {
        if(strcmp(p2->studentNumber,R->studentNumber) == 0)         //该学生已经在黑名单中
        {
            p2->overdueTime++;
            w=0;
            return ;
        }
        p1=p2;
        p2=p1->next;
    }
    if(w!=0)
    {
        p2=(BlackList*)malloc(sizeof(BlackList));
        p2->next=NULL;

        p2->overdueTime=R->overdueTime;
        strcpy(p2->studentName,R->studentName);
        strcpy(p2->studentNumber,R->studentNumber);
        p1->next=p2;
    }
}

//归还
void giveBack()
{
    BorrowRecord *R1;
    R1=(BorrowRecord*)malloc(sizeof(BorrowRecord));
    R1->next=NULL;

    Borrow *p1,*p2;
    p1=(Borrow*)malloc(sizeof(Borrow));
    p2=(Borrow*)malloc(sizeof(Borrow));
    p1->next=NULL;
    p2->next=NULL;

    Book *B;
    B=(Book*)malloc(sizeof(Book));
    B->next=NULL;

    char studentNum[10];
    char name[20];
    char date[10];

    goto_xy(20,10);
    printf("请输入学号：");
    gets(studentNum);
    while(strlen(studentNum)!=8)
    {
        goto_xy(20,22);
        printf("请输入正确的学号");
        goto_xy(20,10);
        printf("                                  ");
        goto_xy(20,10);
        printf("请重新输入：");
        gets(studentNum);
        goto_xy(20,22);
        printf("                                    ");
    }

    R1=searchRecordStudent(studentNum);         //寻找该学生

    if(R1 == NULL)
    {
        goto_xy(20,12);
        printf("你并未借过书");
        Sleep(500);
        return ;
    }
    goto_xy(20,11);
    printf("请输入今天的日期：");
    gets(date);
    while(strlen(date)!=8)
    {
        goto_xy(20,22);
        printf("请输入正确的日期(如20180430)");
        goto_xy(20,11);
        printf("                                           ");
        goto_xy(20,11);
        printf("请重新输入日期：");
        gets(name);
        goto_xy(20,22);
        printf("                                          ");
    }

    goto_xy(20,12);
    printf("请输入你要归还的书的书名:");
    gets(name);
    while(strlen(name)>19)
    {
        goto_xy(20,22);
        printf("请输入正确的书名");
        goto_xy(20,12);
        printf("                                           ");
        goto_xy(20,12);
        printf("请重新输入书名：");
        gets(name);
        goto_xy(20,22);
        printf("                                          ");
    }

    p1=R1->bookHead;
    p2=p1->next;
    int w=0;
    while(p2!=NULL)
    {
        if(strcmp(p2->bookName,name) == 0)
        {
            w=1;
            p1->next=p2->next;
            break;
        }
        p1=p2;
        p2=p1->next;
    }
    if(w!=0)
    {
        goto_xy(20,15);
        printf("还书成功");
        B=p2->book;
        (B->nowStock)++;
        (R1->bookNum)--;
        if(strcmp(p2->returndate,date)<0)               //逾期归还
            (R1->overdueTime)++;
        if(R1->overdueTime >=3)
            addBlacklist(R1);
    }
    else
    {
        goto_xy(20,15);
        printf("你并没有借这本书");
    }
    Sleep(1000);
}

/*********查看**********/
//管理员查看所有借书记录
void ViewRecord()
{
    system("cls");
    BorrowRecord *p;
      p=(BorrowRecord*)malloc(sizeof(BorrowRecord));
      p->next=NULL;

    p=Record->next;
    if(p == NULL)
    {
        goto_xy(20,7);
        printf("当前无学生借阅");
        Sleep(700);
        return ;
    }
    printf("\n\n\t\t\t借阅记录\n\n\t\t姓名\t\t学号\t\t借阅量\t逾期次数\n");
    while(p!=NULL)
    {
        printf("\t\t%-16s",p->studentName);
        printf("%-16s",p->studentNumber);
        printf("%-12d%d\n",p->bookNum,p->overdueTime);
        p=p->next;
    }
    getchar();
}

//学生查看自己的借阅情况
void ViewSelf()
{
    char studentNum[10];
    goto_xy(20,10);
    printf("请输入学号");
    gets(studentNum);
    while(strlen(studentNum)>9)
    {
        goto_xy(20,22);
        printf("请输入正确的学号");
        goto_xy(20,10);
        printf("                                  ");
        goto_xy(20,10);
        printf("请重新输入：");
        gets(studentNum);
        goto_xy(20,22);
        printf("                                    ");
    }

    system("cls");
    BorrowRecord *p;
      p=(BorrowRecord*)malloc(sizeof(BorrowRecord));
      p->next=NULL;
    p=searchRecordStudent(studentNum);
    if(p == NULL)
    {
        goto_xy(20,10);
        printf("你并未借过书");
        getchar();
        return ;
    }

    Borrow *B;
      B=(Borrow*)malloc(sizeof(Borrow));
      B->next=NULL;
    B=p->bookHead;
    B=B->next;
    if(B == NULL)
    {
        goto_xy(20,10);
        printf("你当前并未借书");
        getchar();
        return ;
    }
    printf("\n\n\n\n\t\t书名\t\t  应还日期\n");
    while(B!=NULL)
    {
        printf("\t\t%-19s",B->bookName);
        printf("%-10s\n",B->returndate);
        B=B->next;
    }
    getchar();
}

//显示所有图书
void outputAllBook()
{
    system("cls");
    Library *p;
    p=(Library*)malloc(sizeof(Library));
    p->next=NULL;

    Book *B;
    B=(Book*)malloc(sizeof(Book));
    B->next=NULL;

    p=Lib->next;
    if(p == NULL)
    {
        goto_xy(20,15);
        printf("当前无库存图书");
        Sleep(1000);
        return ;
    }
    printf("\n\n\n\n\t\t类型  书名                  作者                 书号\t现存量\n");
    while(p!=NULL)
    {
        B=p->bookHead;
        B=B->next;
        while(B!=NULL)
        {
            printf("\t\t%3c   ",p->book_Kind);
            printf("%-19s   ",B->name);
            printf("%-19s   ",B->author);
            printf("%-8s",B->num);
            printf("%d\n",B->nowStock);
            B=B->next;
        }
        p=p->next;
    }
    getchar();
}

//查看黑名单
void LookBlackList()
{
    system("cls");
    BlackList *p;
      p=(BlackList*)malloc(sizeof(BlackList));
      p->next=NULL;

    p=Black->next;
    if(p == NULL)
    {
        goto_xy(20,7);
        printf("无黑名单");
        Sleep(500);
        return ;
    }
    printf("\n\n\t\t\t黑名单记录\n\n\t\t姓名\t\t学号\t\t逾期次数\n");
    while(p!=NULL)
    {
        printf("\t\t%-18s",p->studentName);
        printf("%-14s",p->studentNumber);
        printf("%d\n",p->overdueTime);
        p=p->next;
    }
    getchar();
}

/*****************菜单***********************/
//欢迎输出界面
void welcome()
{
    int i;
    goto_xy(30,4);
    printf("欢迎来到学生管理系统");
    goto_xy(17,5);
    printf("--------------------------------------------------");
    goto_xy(17,20);
    printf("--------------------------------------------------");
    for(i=5;i<21;i++)
    {
        goto_xy(16,i);
        printf("$");
        goto_xy(66,i);
        printf("$");
    }
    goto_xy(70,10);
    printf("管理员密码为123,学号为8位数,");
    goto_xy(70,11);
    printf("书名作者请控制在20字符以内，");
    goto_xy(70,12);
    printf("否则会报错.");
    goto_xy(70,13);
    printf("一个人最多可借5本书，");
    goto_xy(70,14);
    printf("逾期归还超过3次会被加入黑名单");
}

//管理员菜单
void AdministratorMenu()
{
    system("cls");
    welcome();
    goto_xy(25,10);
    printf("1.图书入库");
    goto_xy(25,11);
    printf("2.清除库存");
    goto_xy(25,12);
    printf("3.查看所有图书");
    goto_xy(25,13);
    printf("4.查看黑名单");
    goto_xy(25,14);
    printf("5.查看记录");
    goto_xy(25,15);
    printf("6.退出");
    int a;
    goto_xy(25,16);
    printf("请选择：");
    scanf("%d",&a);
    getchar();
    switch(a)
    {
        case 1: input();
                break;
        case 2: destroyBook();
                break;
        case 3: outputAllBook();
                break;
        case 4: LookBlackList();
                break;
        case 5: ViewRecord();
                break;
        case 6: system("cls");
                menu();
                break;
        default:goto_xy(20,18);
                printf("输入错误，请输入1至6的数字");
                Sleep(1000);
                break;
    }
    system("cls");
    AdministratorMenu();
}

//用户菜单
void StudentMenu()
{
    system("cls");
    welcome();

    goto_xy(25,10);
    printf("1.借书");
    goto_xy(25,11);
    printf("2.还书");
    goto_xy(25,12);
    printf("3.查看所有图书");
    goto_xy(25,13);
    printf("4.借阅情况");
    goto_xy(25,14);
    printf("5.退出");
    int a;
    goto_xy(25,15);
    printf("请选择：");
    scanf("%d",&a);
    getchar();

    system("cls");
    welcome();

    switch(a)
    {
        case 1: borrow();
                break;
        case 2: giveBack();
                break;
        case 3: outputAllBook();
                break;
        case 4: ViewSelf();
                break;
        case 5: system("cls");
                menu();
                break;
        default:goto_xy(20,18);
                printf("输入错误，请输入1至5的数字");
                Sleep(1000);
                break;
    }
    system("cls");
    StudentMenu();
}

//主菜单
void menu()
{
    system("cls");

    int a;
    char possword[10];
    welcome();
    goto_xy(25,9);
    printf("1.管理员");
    goto_xy(25,10);
    printf("2.学生");
    goto_xy(25,11);
    printf("3.退出");
    goto_xy(25,7);
    printf("请选择用户类型：");
    scanf("%d",&a);
    getchar();
    while((a!=1) && (a!=2) && (a!=3))
    {
        goto_xy(30,8);
        printf("错误，请重新输入");
        Sleep(500);
        goto_xy(30,8);
        printf("                ");
        goto_xy(41,7);
        printf("   ");
        goto_xy(41,7);
        scanf("%d",&a);
        getchar();
    }

    system("cls");
    welcome();
    if(a==1)
    {
        goto_xy(25,12);
        printf("请输入密码");
        goto_xy(25,13);
        gets(possword);
        AdministratorMenu();
    }
    if(a == 2)
        StudentMenu();
    if(a == 3)
    {
        //save();
        exit(0);
    }
    system("cls");
    menu();
}

/**********其他**************/
//控制光标移动
void goto_xy(int x,int y)
{
    HANDLE hOut;
    COORD pos={0,0};      /***定义了结构体变量pos，他的两个成员为x和y***/
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hOut,pos);
}












