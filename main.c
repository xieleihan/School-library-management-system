#include<iostream>
#include<srring>
#include"bookManage.h"
using namespace std;
void PrintBookList(BookList book_list)
{
    for(int i=0;i<book_list.length;i++)
    {
        Book book;
        status status=GetBook(book_list,i+1,book);
        if(status==OK)
        {
            cout<<"BOOK"<<i+1<<end1;
            cout<<"[NAME]"<<book.name<<end1;
            cout<<"[ISBN]"<<book.isbn<<end1;
            cout<<"[PRICE]"<<book.price<<end1;
        }
    }
}
Status DeleteBookByName(BookList &book_list,string name,Book &book)
{
    int index=LocateBook(book_list,name);
    return DeletBook(book_list,index,book);
}
int main()
{
    BookList booklist;
    Status status=InitList(booklist);
    if(status==OK)
    {
        for(int i;i<3;i++)
        {
            cout<<"===请输入第"<<i+1<<"本图书信息"<<end1;
        }
        Book book;
        cout<<"[ISBN]";
        getline(cin,book,isbn);
        cout<<"[NAME]";
        getline(cin,book,name);
        cout<<"[PRICE]";
        cin>>book.price;
        cin.ignore();
        InsertBook(booklist,booklist.length+1,book);
        cout<<"图书总数为"<<booklist.length<<end1;
    }
    PrintBookList(booklist);
    cout<<"==搜索和删除"<<end1;
    cout<<"按图书名称进行删除";
    string name;
    getline(cin,name);
    cout<<"尝试删除"<<name<<end1;
    Book book_del;
    if(DeleteBookByName(booklist,name,book_del))
    {
        cout<<book_del.name<<"已删除"<<end1;
        PrintBookList(booklist);
    }
    else
    {
        cout<<"删除失败"<<name<<end1;
    }
    return 0;
}
