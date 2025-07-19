#include<iostream>
using namespace std;
struct node{
    int item;
    node *next;
};
class CLL
{
    private:
        node *last;
    public: 
         CLL();
         void insertStart(int);
         void insertLast(int);
         node* search(int);
         void insertAfter(node *, int);
         void deleteFirst();
         void deleteLast();
         void display();
        // void deleteNode(int);
         ~CLL();
};
CLL::~CLL() {
    while (last) {
        deleteFirst();
    }
}
void CLL::display() {
    if (!last) {
        cout << "List is empty\n";
        return;
    }

    node *t = last->next;
    do {
        cout << t->item << " ";
        t = t->next;
    } while (t != last->next);
    cout << endl;
}
void CLL::deleteNode(int data)
{
    node*temp,*t;
    temp=search(data);
    if(temp)
    {
        if(temp==last)
            deleteLast();
        else
        {
            t=last->next;
            while(t->next!=temp)
                t=t->next;
            t->next=temp->next;
            delete temp;
        }
    }

}
void CLL::deleteLast(){
    if(last){
        node *t=last->next;
        if(t==last){
            delete t;
            last=nullptr;
        }
        else{
            while(t->next!=last){
                t=t->next;
            }
            t->next = last->next;
            delete last;
            last=t;
        }
    }
}
void CLL::deleteFirst(){
    if(last){
        node *t=last->next;
        if(t==last){
            delete t;
            last=nullptr;
        }
        else{
            last->next=t->next;
            delete t;
        }
    }
}
void CLL::insertAfter(node *temp, int data){
    if(temp){
        node *n=new node;
        n->item=data;
        n->next=temp->next;
        temp->next=n;
        if(temp==last){
            last=n;
        }
    }
    else{
        cout<<"invalid node";
    }
}
node* CLL::search(int data){
    if(last){
      node *t=last->next;
     do {
            if (t->item == data) {
                return t;
            }
            t = t->next;
        } while (t != last->next);
    }
    return nullptr;
}
void CLL::insertLast(int data){
    node *n=new node;
    n->item=data;
    if(last){
        n->next=last->next;
        last->next=n;
        last=n;
    }
    else{
        last=n;
        n->next=n;
    }
}
void CLL::insertStart(int data){
    node *n=new node;
    n->item=data;
    if(last){
        n->next=last->next;
        last->next=n;
    }
   else{
     last=n;
     n->next=n;
   }
}
CLL::CLL(){
    last=nullptr;
}