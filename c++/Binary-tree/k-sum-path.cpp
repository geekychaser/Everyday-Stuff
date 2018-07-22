#include <iostream>
#include<vector>
using namespace std;

struct Node 
{
	char key;
	Node * left = nullptr;
	Node * right = nullptr;
};

struct Node * newNode(char key)
{
	Node * temp = new Node;

	temp->key = key;
	temp->left = nullptr;
	temp->right= nullptr;

	return temp;
}

void printVector(vector<int>& v ,int i){
    for(int j=i;j<v.size();j++){
        cout<<v[j]<<endl;
    }
}

void printPath(Node* root , vector<int>& path,int k){
    
    int f=0;
    
    if(root == nullptr)
    return;
    
    path.push_back(root->key);
    
    printPath(root->left,path,k);
    
    printPath(root->right,path,k);
    
    for(int j=path.size()-1;j>=0;j++){
        f+=path[j];
        
        if(k==f)
        printVector(path,j);
    }
    
    path.pop_back();
}



int main() {
  
   Node *root = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right = newNode(-1);
root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(2);

int k = 5;
    vector < int > path;
    
    
    
    printPath(root,path,k);
    

    
  
    
	
	
	return 0;
}
