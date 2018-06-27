#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    
    node(int key){
        this->data = key;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    void delete_node(int key){
        node* temp = this;
        queue<node* >q ;
        q.push(this);
        node* test = nullptr;
        
        while(!q.empty()){
            
            temp = q.front();
            q.pop();
            
            if(temp->data == key){
                test = temp;
            }
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
            
        }
        
        int x = temp->data;
        delete_deepest(temp);
        test->data = x;
    }
    
    void delete_deepest(node* last){
        queue<node*>q;
        node* temp = this;
        q.push(this);
        
        while(!q.empty()){
            
            temp = q.front();
            q.pop();
            
            if(temp->right == last){
                temp->right = nullptr;
                delete(last);
                return;
            }else{
                q.push(temp->right);
            }
            
               if(temp->left == last){
                temp->left = nullptr;
                delete(last);
                return;
            }else{
                q.push(temp->left);
            }
            
            
        }
        
        
    }
    
    void levelOrderTraversal(){
        queue<node* > q;
        node* temp = this;
        
        while(temp!=nullptr){
            cout<<temp->data<<" ";
        
            
            if(temp->left!=nullptr)
                q.push(temp->left);
            
            if(temp->right!=nullptr)
                q.push(temp->right);
                
                temp = q.front();
                q.pop();
            
            
        }
        
      
    }
};

int main() {
    
    node* root = new node(1);
   root->left = new node(2);
    root->left->left = new node(4);
    root->right = new node(3);
    root->left->right = new node(5);
    
    root->levelOrderTraversal();
    cout<<endl;
    
    root->delete_node(3);
    
    root->levelOrderTraversal();
	
	return 0;
}
