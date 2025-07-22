#include<iostream>
using namespace std;

struct node{
    int item;
    node* prev;
};

class Stack{
    private:
        node* top;
    public:
        Stack();
        void push(int);     // Insert
        void pop();         // Delete
        void pick();        // View top
        ~Stack();           // Destructor

};
Stack::~Stack(){
    while(top){
        pop();
    }
}    

void Stack::pick(){
    if(top){
        cout<<top->item<<"\n";
    }
}

void Stack::pop(){
    if(top){
        node *temp=top;
        top=temp->prev;
        delete temp;
    }
}

void Stack::push(int data)
{    
    node *n=new node;
    n->item=data;
    n->prev=top;
    top=n;
}

Stack::Stack(){
    top=nullptr;
}

