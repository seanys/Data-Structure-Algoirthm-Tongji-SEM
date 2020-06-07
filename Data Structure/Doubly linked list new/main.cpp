//double LinkList implement with C++ template
#include<iostream>
using namespace std;
/*template<typename Type>
 class DBListADT
 {
 public:
 virtual void Append(const Type &)=0;
 virtual void Insert(const Type &)=0;
 virtual void Remove(const Type &)=0;
 };
 template<typename T>
 class DLinkListNode:public DBListADT<typename T>//此处必须为实现的类型，当然以派生类的模板类型也可以，但是不能是Type
 {
 public:
 void Append(const T &);//这边也需要是当前类的类型,不能为Type
 void Insert(const T &);
 void Remove(const T &);
 
 
 };*/
template<typename T>class DLinkList;
template<typename Type>
class DNode
{
    friend class DLinkList<Type>;//指定前需声明
public:
    DNode(){next=NULL;prior=NULL;}
    ~DNode(){}
private:
    DNode *next;
    DNode *prior;
    Type data;
};
template<typename T>
class DLinkList
{
public:
    DLinkList()
    {
        //   head=new DNode<T>[sizeof(DNode<T>)];
        head=new DNode<T>;
    }
    ~DLinkList()
    {
        if(head->next==NULL)
            delete head;
        else
        {
            DNode<T> *p=head->next;
            DNode<T>*s=NULL;
            while(p)
            {
                s=p->next ;
                delete p;
                p=s;
            }
        }
    }
    void DeleteElement(size_t position)
    {
        DNode<T> *p=head->next;
        size_t index=1;
        for(;index<position;index++)
            p=p->next ;
        if(p==NULL)
            return ;
        p->prior ->next =p->next ;
        p->next ->prior =p->prior ;
        delete p;
    }
    void InsertElement(T data,size_t position);
    void CreateDLinkList(T a[],int n);
    void PrintDLinkList();
private:
    DNode<T> *head;
    
};
template<typename T> void DLinkList<T>:: InsertElement (T data,size_t position)
{
    DNode<T> *p=head->next;
    size_t index=1;
    for(;index<position;index++)
        p=p->next;
    if(p==NULL)
        return;
    //DNode<T> *s=new DNode<T>[sizeof(DNode<T>)];
    DNode<T> *s=new DNode<T>;
    s->data=data;
    s->next=p;
    s->prior=p->prior;
    p->prior->next=s;
    p->prior=s;
}
template<typename T> void DLinkList<T>::CreateDLinkList(T a[],int n)
{
    DNode<T>*p=head;
    DNode<T>*s=NULL;
    int i=0;
    for(;i<n;i++)
    {
        // s=new DNode<T>[sizeof(DNode)];
        s=new DNode<T>;
        s->data=a[i];
        p->next=s;
        s->prior=p;
        p=s;
    }
    s->next=NULL;
}
template<typename T>void DLinkList<T>::PrintDLinkList ()
{
    DNode<T> *p=head->next;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    DLinkList<int>Dlist;
    Dlist.CreateDLinkList(a,10);
    Dlist.DeleteElement (3);
    Dlist.InsertElement(3,3);
    Dlist.PrintDLinkList();
    return 0;
}
//double LinkList implement with C++ Class
//************************************************************
/*#include<iostream>
 using namespace std;
 class Node
 {
 friend class List;
 public:
 //Node(int a):next(NULL),prior(NULL),data(a){}
 Node(){}
 private:
 Node *next;
 Node *prior;
 int data;
 };
 class List
 {
 public:
 List()
 {
 cout<<"create head DBLinkList"<<endl;
 head=new Node[sizeof(Node)];
 };
 ~List()
 {
 if(head->next==NULL)
 {
 delete head;
 }
 else
 {
 Node *p=head->next;
 Node *s;
 delete head;
 while(p)
 {
 s=p->next ;
 delete p;
 p=s;
 }
 }
 cout<<"destructor called to clear DBLinkList"<<endl;
 }
 void CreateDoubleLink(int a[],int n);
 void DeleteElemData(int position);
 void InsertElement(int data,int position);
 void PrintDList();
 private:
 Node *head;
 };
 void List::CreateDoubleLink (int a[],int n)
 {
 
 head->next =NULL;
 Node *s,*p=head;
 int i=0;
 for(;i<n;i++)
 {
 s=new Node[sizeof(Node)];
 s->data =a[i];
 p->next =s;
 s->prior =p;
 p=s;
 }
 s->next =NULL;
 }
 void List::PrintDList()
 {
 Node *p=head->next ;
 while(p)
 {
 cout<<p->data <<endl;
 p=p->next ;
 }
 }
 void List::DeleteElemData(int position)
 {//可以通过重载delete运算符来达到这个效果，则直接用delete就OK了
 Node *p=head->next ;
 //while(p!=NULL&&p->data !=data)
 //   p=p->next ;
 int i=1;
 for(;i<position;i++)
 p=p->next ;
 if(p==NULL)
 return ;
 p->prior ->next =p->next ;
 p->next ->prior =p->prior ;
 delete p;
 }
 void List::InsertElement (int data,int position)
 {//可以重载new运算符来达到这个效果，则直接用new就OK了
 Node *p=head->next ;
 int i=1;
 for(;i<position;i++)
 p=p->next ;
 Node *s=new Node[sizeof(Node)];
 s->data =data;
 s->prior =p->prior ;
 s->next =p;
 p->prior ->next =s;
 p->prior =s;
 }
 int main()
 {
 List Dlist;
 int a[10]={1,2,3,4,5,6,7,8,9,10};
 Dlist.CreateDoubleLink (a,10);
 Dlist.DeleteElemData(3);
 Dlist.InsertElement (3,3);
 Dlist.PrintDList ();
 return 0;
 }*/ 
