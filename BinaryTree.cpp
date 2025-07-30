#include<iostream>
using namespace std;
struct node{
    node *left;
    int item;
    node *right;
};
class BST{
    private:
        node *root;
    public:
        BST();
    bool isEmpty();
    void insert(int);
}
BST::BST(){
    root=nullptr;
}

bool BST::isEmpty(){
    return root==nullptr;
}

void BST::insert(int data){
    node *ptr;
    node *n=new node;
    n->item=data;
    n->right=nullptr;
    n->left=nullptr;
    if(isEmpty())
        root=n;
    else{
        ptr=root;
        while(ptr->item!=data){
            if(data<ptr->item)//insert in left
            {
                    if(ptr->left!=nullptr){
                        ptr=ptr->left;
                    }
                    else{
                        ptr->left=n;
                        break;
                    }
            }
            else//insert in right
            {
                if(ptr->right!=nullptr)
                    ptr=ptr->right;
                else{
                    ptr->right=n;
                    break;
                }
            }   
        }
        if(ptr->item==data)
            delete n;
    }   
}