#include <iostream>
#include<string>
using namespace std;

struct node{
    char data;
    node* left ;
    node* right;
};

struct node* newNode(char data){
    struct node* temp = new node;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->data =  data;
    return(temp);
}

void inorder(struct node* temp, string& s){
    
    
    if(temp == nullptr){
        s.push_back('$');
    return;
    }
    
    inorder(temp->left,s);
    
    s.push_back(temp->data);
   // cout<<temp->left<<" ";
    
    inorder(temp->right,s);
}

void preorder(struct node* temp, string& s){
    
     
    if(temp == nullptr){
        s.push_back('$');
    return;
    }
    
    s.push_back(temp->data);
   // cout<<temp->left<<" ";
    
    preorder(temp->left,s);
    
    
    
    inorder(temp->right,s);
    
}

bool checksubstr(struct node* tree , struct node* stree){
    
    if(stree == nullptr)
    return true;
    
    
    string s1,s2,s3,s4;
    
    inorder(tree,s1);
    inorder(stree,s2);
    
    preorder(tree,s3);
    preorder(stree,s4);
    
    if(s1.find(s2) != string::npos && s3.find(s4) != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
    
    
    
    
}

int main() {
    
    node *T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    node *S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');

    if(checksubstr(T,S))
    {
    	cout<<"YES"<<endl;
    }
    else
    {
    	cout<<"NO"<<endl;
    }


	return 0;
}
