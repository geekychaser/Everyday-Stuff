#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

int global_max = INT_MIN;

struct Node 
{
	char key;
	Node * left = nullptr;
	Node * right = nullptr;
};

struct Node * newNode(char key)
{
	Node * temp = new Node;

	temp->key = key;
	temp->left = nullptr;
	temp->right= nullptr;

	return temp;
}

int max_value(Node* root){
    if(root == nullptr)
    return 0;
    
    int left = max_value(root->left);
    int right = max_value(root->right);
    
    if(global_max < root->key+left+right)
    global_max = root->key+left+right;
    
    return max(root->key+left,root->key+right);
}

int main() {
  
   struct Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    
    max_value(root);
    
    cout<<global_max;
    
	
	
	return 0;
}
