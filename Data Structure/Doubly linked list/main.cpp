#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

//结点类
class Node {
public:
    int data;
    Node *pPre, *pNext;
};

//双向链表类
class DoubleLinkList {
public:
    //构造初始函数
    DoubleLinkList() {
        head = new Node;
        head->data = 0;
        head->pNext = NULL;
        head->pPre = NULL;
    }
    //析构函数
    ~DoubleLinkList() {delete head;}
    void CreateLinkList(int n);                //创建链表
    void InsertNode(int position, int d);    //在指定位置处插入结点
    void TraverseLinkList();                //遍历链表
    bool IsEmpty();                            //判断链表是否为空
    int GetLength();                        //获得链表长度
    int SearchData(int searchData);                      //查找一个Data的位置
    int SearchNode(int position);                      //查找一个Data的位置
    void DeleteNode(int position);            //删除指定位置处结点
    void DeleteLinkList();                    //删除链表
private:
    //初始的head是private的
    Node *head;
};

void DoubleLinkList::CreateLinkList(int n) {
    if (n < 0) {
        cout << "输入结点个数错误！" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        int i = 0;
        Node *pnew, *ptemp;
        ptemp = head;//head是Double link listh中的一个public对象
        i = n;
        
        srand((unsigned)time(NULL));
        //生成随机数
        for(int i=0;i<n;i++){
            pnew = new Node;
            pnew->data=rand()%1000+1;
            pnew->pNext = NULL;
            pnew->pPre = ptemp;
            ptemp->pNext = pnew;
            ptemp = pnew;
        }
    }
}

void DoubleLinkList::InsertNode(int position, int d) {
    if (position < 0 || position > GetLength() + 1){
        cout << "输入位置错误！" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        Node *pnew, *ptemp;
        pnew = new Node;
        pnew->data = d;
        ptemp = head;
        
        while (position-- > 1)
            ptemp = ptemp->pNext;
        
        if (ptemp->pNext != NULL)
            ptemp->pNext->pPre = pnew;
        pnew->pNext = ptemp->pNext;
        pnew->pPre = ptemp;
        ptemp->pNext = pnew;
        ptemp = pnew;
    }
}

void DoubleLinkList::TraverseLinkList() {
    Node *ptemp = head->pNext;
    while (ptemp != NULL) {
        cout << ptemp->data << " ";
        ptemp = ptemp->pNext;
    }
    cout << endl;
}

bool DoubleLinkList::IsEmpty() {
    if (head->pNext == NULL)
        return true;
    else
        return false;
}

int DoubleLinkList::SearchData(int searchData) {
    int n = 0;
    Node *ptemp = head->pNext;
    while (ptemp != NULL&&ptemp->data!=searchData) {
        n++;
        ptemp = ptemp->pNext;
    }
    if(ptemp == NULL){
        cout<<"未搜索到该位置"<<endl;
        return -1;
    }else{
        cout<<"该值的位置："<<n<<endl;
        return n;
    }
}
    
int DoubleLinkList::SearchNode(int position) {
    int n = 0;
    Node *ptemp = head->pNext;
    while (ptemp != NULL&&n!=position-1) {
        n++;
        ptemp = ptemp->pNext;
    }
    if(ptemp==NULL){
        cout<<"无法查找到该位置"<<endl;
    }else{
        cout<<"该位置的值为："<<ptemp->data<<endl;
    }
    return n;
}


int DoubleLinkList::GetLength() {
    int n = 0;
    Node *ptemp = head->pNext;
    while (ptemp != NULL) {
        n++;
        ptemp = ptemp->pNext;
    }
    cout<<"长度为："<<n<<endl;
    return n;
}

void DoubleLinkList::DeleteNode(int position) {
    if (position < 0 || position > GetLength()) {
        cout << "输入数据错误!" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        Node *pdelete, *ptemp;
        ptemp = head;
        
        while (position-- > 1)
            ptemp = ptemp->pNext;
        pdelete = ptemp->pNext;
        if (pdelete->pNext != NULL)
            pdelete->pNext->pPre = ptemp;
        ptemp->pNext = pdelete->pNext;
        delete pdelete;
        pdelete = NULL;
    }
}

void DoubleLinkList::DeleteLinkList() {
    Node *pdelete, *ptemp;
    pdelete = head->pNext;
    while (pdelete != NULL) {
        ptemp = pdelete->pNext;
        head->pNext = ptemp;
        if (ptemp != NULL)
            ptemp->pPre = head;
        delete pdelete;
        pdelete = ptemp;
    }
}

//测试函数
int main() {
    DoubleLinkList dl;
    int position = 0, value = 0, n = 0;
    bool flag = false;
    
    cout << "请输入需要创建双向链表的结点个数：";
    cin >> n;
    dl.CreateLinkList(n);
    
    cout << "打印链表值如下：";
    dl.TraverseLinkList();
    
//    cout << "长度为：";
    dl.GetLength();
//    cout<<endl;
    
    cout << "请输入要查找结点的值：";
    int searchData;
    cin >> searchData;
    dl.SearchData(searchData);

    cout << "请输入要查找的结点位置：";
    int searchNode;
    cin >> searchNode;
    dl.SearchNode(searchNode);

    
    cout << "请输入插入结点的位置和值：";
    cin >> position >> value;
    dl.InsertNode(position, value);
    
    cout << "打印链表值如下：";
    dl.TraverseLinkList();
    
    cout << "请输入要删除结点的位置：";
    cin >> position;
    dl.DeleteNode(position);

    cout << "打印链表值如下：";
    dl.TraverseLinkList();
    
    dl.DeleteLinkList();
    flag = dl.IsEmpty();
    if (flag)
        cout << "删除链表成功！" << endl;
    else
        cout << "删除链表失败！" << endl;
    cout << "结束" << endl;
    return 0;
}

