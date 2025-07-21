#include<iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class SLL
{
    private:
        node *start;
    public: 
        SLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node *,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int);
        ~SLL();
};
SLL::SLL()
{
    start=nullptr;
}
void SLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL::insertAtLast(int data)
{
    node *n=new node;
    node *t;
    n->item=data;
    n->next=nullptr;
    if(start==nullptr)
    {
        start=n;
    }
    else
    {
        t=start;
        while(t->next!=nullptr)
            t=t->next;
        t->next=n;
    }
}
node* SLL::search(int data)
{
    node *t;
    t=start;
    while(t!=nullptr)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return nullptr;
}
void SLL::insertAfter(node *t,int data)
{
    if(t!=nullptr){
        node *n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
void SLL::deleteFirst()
{
    node *t;
    if(start)
    {
        t=start;
        start=start->next;
        delete t;
    }
}
void SLL::deleteLast()
{
    node *t;
    if(start)
    {
        if(start->next==nullptr)
        {
            delete start;
            start=nullptr;
        }
        else
        {
            t=start;
            while(t->next->next!=nullptr)
                t=t->next;
            delete t->next;
            t->next=nullptr;
        }
    }
}
void SLL::deleteNode(int data)
{
    node *t1,*t2;
    if(start)
    {
        t2=search(data);
        if(t2)
        {
            t1=start;
            if(t1==t2)
                deleteFirst();
            else
            {
                while(t1->next!=t2)
                    t1=t1->next;
                t1->next=t2->next;
                delete t2;
            }
            
        }
    }
}
SLL::~SLL()
{
    while(start)
        deleteFirst();
}