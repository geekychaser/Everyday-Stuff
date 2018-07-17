

#include <iostream>
using namespace std;


struct node 
{
	char key;
	node * left = nullptr;
	node * right = nullptr;
};

struct node * newNode(char key)
{
	node * temp = new node;

	temp->key = key;
	temp->left = nullptr;
	temp->right= nullptr;

	return temp;
}

void inorder(struct node* root){
    if(root == nullptr)
    return;
    
    inorder(root->left);
    
    cout<<root->key<<" ";
    
    inorder(root->right);
}





node* insert( node* node , int key){
    
    if(node == nullptr)
    return newNode(key);
    
    if(key < node->key){
        node->left = insert(node->left,key);
    }
    
    if(key> node->key){
        node->right = insert(node->right,key);
    }
    
    return node;
}

int main() {
    struct node *root = NULL;
	root = insert(root, 'a');
	insert(root, 'b');
	insert(root, 'c');
	insert(root, 'd');
	
	
	inorder(root);

	return 0;
}
