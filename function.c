#include"bookManage.h"

//创建空表
Status iniList(BookList &book_list);
{
    book_list.books=new Book[MAXSIZE];/*new 开辟内存空间，和malloc作用是一样的，大小由MAXSIZE决定*/
    if(book_list.books==NULL)//判断图书结构体是否为空
    {
        exit(OVERFLOW);
    }
    book_list.length=0;/*图书列表的长度初始化为0*/
    return OK;
}
//插入图书(插到i前面)

Status InsertBook(BookList &book_list,int i,Book book);
{
    if(i<1||i>book_list.length+1)
    {
        return ERROR;
    }
    if(book_list.length>=MAXSIZE)
    {
        return ERROR;
    }
    //为新元素腾出位置
    for(int j=book_list.length-1;j>=i-1;j--)
    {
        book_list.books[j+1]=book_list.books[j];
    }
    //插入新元素
    book_list.books[i-1]=book;
    book_list.length++;
    return OK;
}

//查找 根据索引i

Status Getbook(BookList &book_list,int i,Book &book);
{
    if(i<1||i>book_list.length+1)
    {
        return ERROR;
    }
    //这里可以直接查找 为什么要-1？下标从零开始
    book=book_list.books[i-1];
    return OK;
}

//查找 根据名称

int LocateBook(Booklist &book_list,string name);
{
    for(int i=0;i<book_list.length;i++)
    {
        if(book_list.books[i].name.compare(name)==0)
        {
            return i+1;
        }
    }
    return OK;
}

//删除

Status DeletBook(BookList &book-list,int i,Book &book);
{
    if(i<1||i>book_list.length+1)
    {
        return ERROR;
    }
    book=book_list.books[i-1];
    for(int j=0;j<=book_list.length-1;j++)
    {
        book_list.books[j-1]=book_list.books[j];
    }
    book_list.length--;
    return OK;
}
