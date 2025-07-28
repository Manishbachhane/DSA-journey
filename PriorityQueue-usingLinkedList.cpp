#include<iostream>
using namespace std;
struct node{
    int item;
    int pno;//priority number
    node *next;
};
class PriorityQueue{
    private:
        node *start;
    public:
        PriorityQueue();
        void insertData(int,int);
        int deleteData();
        int get_Highest_Priority_Element();
        int get_Highest_Priority_Number();
        ~PriorityQueue();
        bool isEmpty();
};
PriorityQueue::PriorityQueue(){
    start=nullptr;
}
void PriorityQueue::insertData(int data,int pno){
    node *n=new node;
    node *t;
    n->item=data;
    n->pno=pno;
    if(start==nullptr){
        n->next=nullptr;
        start=n;
    }
    else if(start->pno<pno){
        n->next=start;
        start=n;
    }
    else{
        t=start;
        while(t->next!=nullptr){
            if(t->next->pno<pno){
                break;
            }
            t=t->next;
        }
        n->next=t->next;
        t->next=n;  
    }
}
int PriorityQueue::deleteData(){
    int data;
    if(start){
        node *t=start;
        data=start->item;
        start=start->next;
        delete t;
        return data;
    }
    return -1;
}
int PriorityQueue::get_Highest_Priority_Element(){
    if(start){
        return start->item;
    }
    return -1;
}
int PriorityQueue::get_Highest_Priority_Number(){
     if(start){
        return start->pno;
    }
    return -1;
}
PriorityQueue::~PriorityQueue(){
    while(start)
        deleteData();
}
bool PriorityQueue::isEmpty(){
    return start==nullptr;
}