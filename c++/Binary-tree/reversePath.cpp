#include<iostream>
#include<vector>
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

void reverseTreePath(node* root,vector<node* >&v,int key){
    bool static flag = false;

    

    if(root == nullptr)
    return;

    if(root->data == key){
        flag = true;
    }

    if(flag == false){
    reverseTreePath(root->left,v,key);
    }
  
    if(flag){
     
        v.push_back(root);
    }

    if(flag == false){
      reverseTreePath(root->right,v,key);
    }
}

void rev_vec(vector<node*>&v){

    int temp;
    auto s = v.begin();
    auto l = v.end()-1;

    while(s<l){
        temp = (*s)->data;
        (*s)->data = (*l)->data;
        (*l)->data = temp;

        s++;
        l--;
    }
}

void reverse(node* root,int key){
    if(root == nullptr)
    return;

    vector<node*>v;

     reverseTreePath(root,v,key);
     rev_vec(v);


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
   
    node* root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);
 
   
 
    int data = 4;
 
   
    reverse(root, data);
 

    inorder(root);
    return 0;
}