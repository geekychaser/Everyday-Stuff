
#include <iostream>
#include <queue>
using namespace std;

struct node {
	int key;
	struct node* left, *right;
};


struct node* newnode(int key)
{
	struct node* temp = new node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};


void inorder(struct node* temp)
{
	if (!temp)
		return;

	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}


void insert(struct node* temp, int key)
{
	queue<struct node*> q;
	q.push(temp);

 
	while (!q.empty()) {
		struct node* temp = q.front();
		q.pop();

		if (!temp->left) {
			temp->left = newnode(key);
			break;
		} else
			q.push(temp->left);

		if (!temp->right) {
			temp->right = newnode(key);
			break;
		} else
			q.push(temp->right);
	}
}

// Driver code
int main()
{
	struct node* root = newnode(10);
	root->left = newnode(11);
	root->left->left = newnode(7);
	root->right = newnode(9);
	root->right->left = newnode(15);
	root->right->right = newnode(8);

	cout << "Inorder traversal before insertion:";
	inorder(root);


	insert(root, 12);

	cout << endl;
	cout << "Inorder traversal after insertion:";
	inorder(root);

	return 0;
}

