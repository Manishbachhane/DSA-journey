#include<iostream>
using namespace std;
struct node{
    int item;
    node *next;
};
class Queue{
        private:
           node *front;
           node *rear;
        public:
            Queue(int);
        void insert(int);//rear
        void viewRear();//view Rear
        void viewFront();//view Front
        void delet();//front
            ~Queue();
        int count();//total eliments
};
Queue::Queue(){
    front = rear = nullptr;
}
void Queue::insert(int data)//rear
{
    node *n=new node;
    n->item=data;
    n->next=nullptr;
    if(front==nullptr)
        front=rear=n;
    else{
        rear->next=n;
        rear=n;
    }
}
void Queue::viewRear()//view Rear
{
    if(rear){
        cout<<rear->item<<endl;
    }
    else{
        cout<<"Queue is empty";
    }
}
void Queue::viewFront()//view Front
{
    
    if(front){
        cout<<front->item<<endl;
    }
    else{
        cout<<"Queue is empty";
    }
}
void Queue::delet()//front
{
    if(front){
        node *temp=front;
        front=temp->next;
        delete temp;
        if(front == nullptr) {
            rear = nullptr; 
        }
    }
    else{
        cout<<"Queue is empty";
    }
}  
Queue::~Queue(){
    while(front){
        delet();
    }
}
int  Queue::count()//total eliments
{
    if(front){
        node *temp=front;
        int i=0;
        do{
            i++;
            temp=temp->next;
        }while(temp!=nullptr);
        return i;
    }
    return 0;
}
