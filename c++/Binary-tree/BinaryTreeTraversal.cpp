#include <iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node* right;
};

struct node* newnode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
};

void inorder(struct node* temp){
    
    if(temp==NULL)
    return;
    
    
    inorder(temp->left);
    
    cout<<temp->data<<" ";
    

    
    inorder(temp->right);
    
   
}

int postorder(struct node* temp){
    if(temp == NULL)
    return 0;
    
   int k =  postorder(temp->left);
   k=k+1;
   cout<<"k is "<<k<<endl;
   int l =  postorder(temp->right);
   l=l+1;
   cout<<"l is "<<l<<endl;
   // cout<<temp->data<<" ";
   //out<<l<<k;
    
    return (l>k)?l:k;
    
//     if(k>l)
// 	return(k+1);
// 	else
// 	return(l+1);
}

void preorder(struct node* temp){
    if(temp == NULL)
    return;
    
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
int main() {
    
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    
//     cout<<"inorder traversal";
//   inorder(root);
//     cout<<endl;

  
    
    cout<<"post order ";
   int p =  postorder(root);
    cout<<endl;
    cout<<p<<endl;
    
    // cout<<"preorder ";
    // preorder(root);
    // cout<<endl;
   
	
	return 0;
}
