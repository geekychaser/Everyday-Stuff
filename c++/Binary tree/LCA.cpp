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

struct Node* findLCA(Node* root,int n,int m){
    
    if(root==nullptr)
    return nullptr;
    
    if(root->key == n || root->key == m){
        return root;
    }
    
    Node* left_lca = findLCA(root->left,n,m);
    Node* right_lca = findLCA(root->right,n,m);
    
    if(left_lca && right_lca){
        return root;
    }
    
    if(left_lca!=nullptr){
        return left_lca;
    }else
    return right_lca;
}



int main() {
    
    	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key<<endl;
	cout << "LCA(4, 6) = " << findLCA(root, 4, 6)->key<<endl;
	cout << "LCA(3, 4) = " << findLCA(root, 3, 4)->key<<endl;
	cout << "LCA(2, 4) = " << findLCA(root, 2, 4)->key<<endl;

	return 0;
}
