#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"library.h"

int main()
{
    Lib=(Library*)malloc(sizeof(Library));
    Lib->next=NULL;

    Record=(BorrowRecord*)malloc(sizeof(BorrowRecord));
    Record->next=NULL;

    Black=(BlackList*)malloc(sizeof(BlackList));
    Black->next=NULL;

    menu();

    return 0;
}


