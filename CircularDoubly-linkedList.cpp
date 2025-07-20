#include<iostream>
using namespace std;
struct node{
    node *prev;
    int item;
    node *next;
};
class CDLL
{
    private:
        node *start;
    public:
      CDLL();
     ~CDLL();
    void insertStart(int);
    void insertAtLast(int);
    node* search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
};
CDLL::CDLL(){
    start=nullptr;
}
void CDLL::insertStart(int data){
    node *n=new node;
    n->item=data;
    if(start){
        n->next=start;
        n->prev=start->prev;
        n->next->prev=n;
        n->prev->next=n;
        //start=n;
    }
    else{
        n->next=n;
        n->prev=n;
    }
    start=n;
}
void CDLL::insertAtLast(int data){
    node *n=new node;
    n->item=data;
    if(start){
        n->next=start;
        n->prev=start->prev;
        n->next->prev=n;
        n->prev->next=n;
    }
    else{
        n->next=n;
        n->prev=n;
        start=n;
    }
}
node*CDLL:: search(int data){
    if(start){
        node *t=start;
        do {
            if (t->item == data)
                return t;
            t = t->next;
        } while (t != start);
    }
    return nullptr;
}
void CDLL::insertAfter(node *temp, int data){
    if(temp){
        node *n=new node;
        n->item=data;
        n->next=temp->next;
        n->prev=temp;
        n->next->prev=n;
        temp->next=n;
    }
    else{
        cout<<"invalid node !\n";
    }
}
void CDLL::deleteFirst(){
    if(start){
        node *t=start;
        if(start->next==start){
            delete t;
            start=nullptr;
        }
        else{
            start=t->next;
            t->prev->next=start;
            start->prev=t->prev;
            delete t;
        }
    }
}
void CDLL::deleteLast(){
    if(start){
        node *t=start->prev;
        if(start->next==start){
            delete t;
            start=nullptr;
        }
        else{
            t->prev->next=start;
            start->prev=t->prev;
            delete t;
        }
    }
}
void CDLL::deleteNode(int data){
    node *t=search(data);
       if (t) {
        if (t->next == t) {
            delete t;
            start = nullptr;
        }
        else {
            if (t == start)
                start = t->next;
            t->next->prev = t->prev;
            t->prev->next = t->next;
            delete t;
        }
    }
}
CDLL:: ~CDLL(){
    while(start)
        deleteFirst();
}