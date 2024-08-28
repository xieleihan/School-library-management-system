#ifndef BOOKMANAGE_H

#define BOOKMANAGE_H

#define MAXSIZE 10000



#include<string>

#include"status.h"

using namespace std;



//图书结构

typedef struct{

    string isbn;

    string name;

    float price;

}Book



//图书列表 基于顺序表

typedef struct{

    Book *book:

    int length;

}SqBooklist;



typedef SqbookList BookList;



//创建空表

STATUS iniList(BookList &book_list);

//插入图书

status InsertBook(BookList &book_list,int i,Book book);

//查找 根据索引i

Status Getbook(BookList &book_list,int i,Book &book);

//查找 根据名称

int LocateBook(Booklist &book_list,string name);

//删除

Status DeletBook(BookList &book-list,int i,Book &book);



#endif
