#include <iostream>  // Needed for cout, endl
using namespace std;
class Array{
    private:
        int *arr;
        int lastIndex;// what the last value 
        int capacity;//fixed size not change
    public:
        Array(int);//size
        void append(int);
        int search(int);//vale
        void deletLast();//delet last
        void deletFirst();//delet first
        void insert(int,int);
        bool isFull();
        void edit(int,int);
        void display();
       ~Array();  
};
void Array::display() {
    for (int i = 0; i <= lastIndex; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void Array::edit(int index,int data){
    if(index>=0  && index<=lastIndex){
        arr[index]=data;
    }
    else {
    cout << "Invalid index\n";
    }
}

bool Array::isFull(){
    return lastIndex+1==capacity;
}

void Array::insert(int index,int data){
   if(!isFull()){
     if(index>=0 && index<=lastIndex+1){
        if(lastIndex+1 == index){
            arr[index]=data;
        }
        else{
            for(int i=lastIndex;i>=index;i--){
                arr[i+1]=arr[i];
            }
            arr[index]=data;
        }
        lastIndex++;    
    }
    else{
        cout<<"invalid index !";
    }
   }
   else{
    cout<<"array alrady full";
   }
}
void Array::deletFirst(){
    if(lastIndex==-1){
        cout<<"alredy empty";
    }
    else if(lastIndex==0){
        lastIndex--;//no need shifting    
    }
    else{
        for(int i=0;i<lastIndex;i++){
            arr[i]=arr[i+1];
        }
        lastIndex--;
   
    }
}

void Array::deletLast(){
    if(lastIndex>=0){
        lastIndex--;
        cout<<"delet succesfull !";
    }
    else{
        cout<<"deletion not possible";
    }
}

int Array::search(int value){
        for(int i=0;i<=lastIndex;i++){
            if(arr[i]==value)return i;
        }
        return -1;
}

void Array::append(int data){
    if(capacity!=lastIndex+1){
        lastIndex++;
        arr[lastIndex]=data;
    }
    else{
        cout<<"Array is full";
    }
}

Array::~Array(){
   delete[] arr;
}

Array::Array(int size){
    lastIndex = -1;
    capacity = size; // Default capacity
    arr = new int[capacity];
}

int main(){
    Array a(5);
    a.append(10);
    a.append(20);
    a.append(30);
    a.append(40);
    a.append(50);
    a.display();
    a.append(50);
    cout<<a.search(60);
    a.deletLast();
    a.display();
}