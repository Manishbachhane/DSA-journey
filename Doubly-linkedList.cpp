#include<iostream>
using namespace std;

struct node {
    node *prev;
    int item;
    node *next;
};

class DLL {
private:
    node *start;
public:
    DLL();
    ~DLL();
    void insertStart(int);
    void insertAtLast(int);
    node* search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
};

DLL::DLL() {
    start = nullptr;
}

DLL::~DLL() {
    while(start) {
        deleteFirst();
    }
}

void DLL::insertStart(int data) {
    node *n = new node;
    n->item = data;
    n->next = start;
    n->prev = nullptr;
    if (start != nullptr)
        start->prev = n;
    start = n;
}

void DLL::insertAtLast(int data) {
    node *n = new node;
    n->item = data;
    n->next = nullptr;
    n->prev = nullptr;

    if (start == nullptr) {
        start = n;
    } else {
        node *t = start;
        while (t->next != nullptr)
            t = t->next;
        t->next = n;
        n->prev = t;
    }
}

node* DLL::search(int data) {
    node *t = start;
    while (t != nullptr) {
        if (t->item == data)
            return t;
        t = t->next;
    }
    return nullptr;
}

void DLL::insertAfter(node *temp, int data) {
    if (temp) {
        node *n = new node;
        n->item = data;
        n->next = temp->next;
        n->prev = temp;
        if (temp->next != nullptr)
            temp->next->prev = n;
        temp->next = n;
    } else {
        cout << "Invalid node\n";
    }
}

void DLL::deleteFirst() {
    if (start) {
        node *t = start;
        start = start->next;
        if (start != nullptr)
            start->prev = nullptr;
        delete t;
    }
}

void DLL::deleteLast() {
    if (start == nullptr) {
        cout << "Already empty!\n";
    } else if (start->next == nullptr) {
        delete start;
        start = nullptr;
    } else {
        node *t = start;
        while (t->next != nullptr)
            t = t->next;
        t->prev->next = nullptr;
        delete t;
    }
}

void DLL::deleteNode(int data) {
    node *temp = search(data);
    if (temp) {
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        else
            start = temp->next;
        delete temp;
    }
}
