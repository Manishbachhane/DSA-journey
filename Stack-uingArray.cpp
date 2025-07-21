#include<iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int);
    void push(int);     // Insert
    void pop();         // Delete
    void pick();        // View top
    ~Stack();           // Destructor
};

Stack::Stack(int size) {
    capacity = size;
    top = -1;
    arr = new int[capacity];
}

void Stack::push(int data) {
    if (top < capacity - 1) {
        arr[++top] = data;
    } else {
        cout << "Stack is full!" << endl;
    }
}

void Stack::pop() {
    if (top >= 0) {
        top--;
    } else {
        cout << "Stack is empty!" << endl;
    }
}

void Stack::pick() {
    if (top >= 0) {
        cout << "Top element: " << arr[top] << endl;
    } else {
        cout << "Stack is empty!" << endl;
    }
}

Stack::~Stack() {
    delete[] arr;
}
