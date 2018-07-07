#include <iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data){
    struct node* temp = new node;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->data = data;
    return (temp);
}

bool continuous(struct node* temp){
    
    if(temp == nullptr)
    return true;
    
    if(temp->left == nullptr && temp->right == nullptr)
    return true;
    
    if(temp->left == nullptr){
        return(abs(temp->data - temp->right->data)==1) && continuous(temp->right);
        cout<<abs(temp->data - temp->right->data)<<endl;
    }
    
    if(temp->right == nullptr){
        return(abs(temp->data - temp->right->data)==1) && continuous(temp->left);
        cout<<abs(temp->data - temp->right->data);
    }
    
    return abs(temp->data - temp->right->data)==1 && abs(temp->data - temp->left->data)==1 && continuous(temp->left) && continuous(temp->right);
}

int main() {

struct node *root = newnode(3);
    root->left        = newnode(2);
    root->right       = newnode(4);
    root->left->left  = newnode(1);
    root->left->right = newnode(3);
    root->right->right = newnode(5);
    continuous(root)?  cout << "Yes" : cout << "No";
	return 0;
}
