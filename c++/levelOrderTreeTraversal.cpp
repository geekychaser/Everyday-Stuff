#include <iostream>
#include<cstdlib>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node* right;
};

void presentlevel(struct node* root, int level);
int postorder(struct node* node);
struct node* newNode(int data);

void levelorder(struct node* temp){
    
    int h = postorder(temp);
    
    for(int i=1;i<=h;i++){
        presentlevel(temp,i);
    }
}

void presentlevel(struct node* root , int level){
    if(root == NULL)
    return;
    if(level == 1)
    cout<<root->data<<" ";
    
    else if(level > 1){
        presentlevel(root->left,level-1);
        presentlevel(root->right,level-1);
    }
}



int postorder(struct node* temp){
 if(temp == NULL)
    return 0;
    
   int k =  postorder(temp->left);
   k=k+1;
   
   int l =  postorder(temp->right);
   l=l+1;
   // cout<<temp->data<<" ";
   //out<<l<<k;
    
    return (l>k)?l:k;
}





struct node* newnode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
};






int main() {
	
	struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    
    levelorder(root);
    
	return 0;
}
