#include<iostream>
using namespace std;

class Queue{
        private:
            int capacity;
            int front;//delete
            int rear;//insert
            int *ptr;
        public:
            Queue(int);
        void insert(int);//rear
        void viewRear();//view Rear
        void viewFront();//view Front
        void delet();//front
            ~Queue();
        bool overFlow();//full
        bool underFlow();//not full
        int count();//total eliments
};

Queue:: Queue(int size)
{
    front =-1;
    rear  =-1;
    capacity = size;
    ptr = new int[size];
}
int  Queue::count()//total eliments
{
    if(front!=-1){
        return rear-front+1;
    }
    else{
        return 0;
    } 
}
void Queue::insert(int data)//rear//insert
{
    if(front==-1){
        front++;
        rear++;
        ptr[rear]=data;
    }
    else{
        int c=count();
        if(c==capacity){
            cout<<"Queue is full!\n";
        }
        else{
            if(rear<capacity-1){
                rear++;
                ptr[rear]=data;
            }
            else{
                int i;
                for(i=0;front+i<=rear;i++){
                    ptr[i]=ptr[front+i];
                }
                rear=i-1;
                front=0;
                rear++;
                ptr[rear]=data;
            }
        }
    }
}
void Queue::viewRear()//view Rear
{
    if(front == -1 || front > rear) {
        cout << "Empty Queue\n";
    }
    else {
        cout << ptr[rear] << "\n";
    }
}
void Queue::viewFront()//view Front
{
    if(front == -1 || front > rear) {
        cout << "Empty Queue\n";
    }
    else {
        cout << ptr[front] << "\n";
    }
}
void Queue::delet()//front
{
    if(front ==-1 || front>rear){
        cout << "Empty Queue\n";
    }

    else{
       if(front == rear){
            // Only one element left
            front = rear = -1;
        }
        else{
            front++;
        }
    }
}
Queue::~Queue()
{
    delete[] ptr;
}
bool Queue::overFlow()//full
{
    return rear == capacity - 1;
}
bool Queue::underFlow()//empty check
{
     return front == -1 || front > rear;
}
// int Queue::count()
// {
//     if (front == -1 || front > rear) {
//         return 0;
//     } else {
//         return rear - front + 1;
//     }
// }
