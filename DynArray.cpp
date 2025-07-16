#include<iostream>
using namespace std;
#define OVERFLOW 1
#define INVALID_INDEX 2
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(int);
        DynArray(DynArray&);
        DynArray& operator=(DynArray&);
        bool isEmpty();
        bool isFull();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        int getValue(int);
        int count();
        ~DynArray();
        int find(int);
        
};
DynArray::DynArray(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr= new int[capacity];
}
bool DynArray::isEmpty()
{
    return lastIndex==-1;
}
bool DynArray::isFull()
{
    return lastIndex==capacity-1;
}
void DynArray::append(int data)
{
    if(isFull())
        doubleArray();
    ptr[lastIndex+1]=data;
    lastIndex++;
}
void DynArray::insert(int index,int data)
{
    if(index<0 || index>lastIndex+1)
        throw INVALID_INDEX;
    if(isFull())
        doubleArray();
    for(int i=lastIndex;i>=index ;i--)
        ptr[i+1]=ptr[i];
    ptr[index]=data;
    lastIndex++;
}
void DynArray::doubleArray()
{
    int *temp;
    temp=new int[capacity*2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
void DynArray::halfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;
}
void DynArray::edit(int index,int data)
{
    if(index<0 || index>lastIndex)
        throw INVALID_INDEX;
    ptr[index]=data;
}
int DynArray::getValue(int index)
{
    if(index<0||index>lastIndex)
        throw INVALID_INDEX;
    return ptr[index];
}
int DynArray::count()
{
    return lastIndex+1;
}
DynArray::~DynArray()
{
    delete []ptr;
}
int DynArray::find(int data)
{
    int index;
    for(index=0;index<=lastIndex;index++)
        if(ptr[index]==data)
            return index;
    return -1;
}
void DynArray::del(int index)
{
    if(index<0 || index>lastIndex)
        throw INVALID_INDEX;
    for(int i=index;i<lastIndex ;i++)
        ptr[i]=ptr[i+1];
    lastIndex--;
    if(capacity>1 && count()==capacity/2)
        halfArray();

}