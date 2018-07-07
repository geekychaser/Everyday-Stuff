#include <iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

struct node* newnode(int data){
    struct node* temp = new node;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->data =  data;
    return(temp);
}

void inorder(struct node* temp){
    stack<struct node*>s;
    
    while(true){
    
    if(temp != nullptr){
        s.push(temp);
        temp = temp->left;
    }
    
    else {
        if(!s.empty()){
            temp = s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp = temp->right;
        }
        else{
            return;
        }
    }
    
    
    
    }
    
    
    
    
    
}


int main() {
    struct node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);
   
    
    inorder(root);


	return 0;
}
