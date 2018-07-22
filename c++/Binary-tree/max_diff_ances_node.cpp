
#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;


struct Node
{
	struct Node *left, *right;
	int key;
};


Node* newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

int n=INT_MIN;

int maxdiff(Node* root){
    if(root == nullptr){
        return INT_MAX;
    }
    
 int left_min =  maxdiff(root->left);
  int right_min =  maxdiff(root->right);
    
    n = max(n,max(root->key-left_min,root->key-right_min));
    
    return min(root->key,min(left_min,right_min));
    
    
}
int main()
{

	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	
	maxdiff(root);
	
	cout<<n;
	
	
	return 0;
}

