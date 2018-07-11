
#include <iostream>
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


struct Node *findLCA(struct Node* root, int n1, int n2)
{

	if (root == NULL) return NULL;


	if (root->key == n1 || root->key == n2)
		return root;

	Node *left_lca = findLCA(root->left, n1, n2);
	Node *right_lca = findLCA(root->right, n1, n2);

	if (left_lca && right_lca) return root;

	return (left_lca != NULL)? left_lca: right_lca;
}

void findlevel(Node* root,int n1,int n2,int index,int& level1,int& level2){
    if(root == nullptr)
    return;
    
    if(root->key == n1){
        level1 = index;
    }
    
    if(root->key == n2){
        level2 = index;
    }
    
    findlevel(root->left,n1,n2,index+1,level1,level2);
    findlevel(root->right,n1,n2,index+1,level1,level2);
}

int distance(Node* root , int n,int m){
    
    Node* ances = findLCA(root,n,m);
    int level1 =0;
    int level2 =0;
    
    findlevel(ances,n,m,0,level1,level2);
    
    return level2+level1;
    
    
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
	
	cout<<distance(root,5,6);
	
	
	return 0;
}

