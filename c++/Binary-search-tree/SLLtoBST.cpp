#include<iostream>
#include<list>

using namespace std;

struct node
{
	int data;
	node * left = nullptr;
	node * right = nullptr;
};

struct node * newNode(int key)
{
	node * temp = new node;
	temp->data = key;
	temp->left = nullptr;
	temp->right = nullptr;

	return temp;
}

node* LinkedInsert(auto& it,int n){

    if(n<=0)
    return  nullptr;

    node* left_temp = LinkedInsert(it,n/2);

    node* root = newNode(*it);

    it++;

    root->left = left_temp;

    root->right = LinkedInsert(it,n-n/2-1);

    return root;


}

void inorder(node * root)
{
	if(root == nullptr)
	{
		return;
	}

	inorder(root->left);

	cout<<root->data<<" ";

	inorder(root->right);
}



int main()
{
	
list<int>l {1,2,3,4,5,6,7};

auto it = l.begin();
   node* root =  LinkedInsert(it,l.size());

   inorder(root);

    



    cout<<endl;

    return 0;


}