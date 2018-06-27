#include <iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    
    public:
    
    int key;
    node* left;
    node* right;
    
    
    
    node(int data){
        key = data;
        left = nullptr;
        right = nullptr;
    }
    
    
    
    void levelOrderTraversal(){
        queue<node* > q;
        node* temp = this;
        
        while(temp!=nullptr){
            cout<<temp->key<<" ";
        
            
            if(temp->left!=nullptr)
                q.push(temp->left);
            
            if(temp->right!=nullptr)
                q.push(temp->right);
                
                temp = q.front();
                q.pop();
            
            
        }
        
      
    }
    
    void insert(int data){
        
     queue<node* >q;
     node* temp =  this;
  
     q.push(this);
     while(!q.empty()){
         
         
         if(!temp->left){
             temp->left = new node(data);
             break;
         }else{
             q.push(temp->left);
         }
         
         if(!temp->right){
             temp->right = new node(data);
             break;
         }else{
             q.push(temp->right);
         }
         temp = q.front();
         q.pop();
     }
        
    }
    
    void reverseOrder(){
        queue<node* >q;
        //stack<node* >s;
        stack<int> s;
        node* temp = this;
      //  q.push(this);
        
        while(temp!=nullptr){
            s.push(temp->key);
            
            //s.push(temp);
            
            // if(q.empty()){
            //     return;
            // }
            
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
            temp = q.front();
            q.pop();
           
            }
            
            
        
        
         while(s.empty()==false){
                //node* temp = s.top();
                cout<<s.top()<<" ";
                s.pop();
         }
        
    }
    
  
    
};



int main() {
    
    node* root = new node(1);
   root->left = new node(2);
    root->left->left = new node(4);
    root->right = new node(3);
   // root->right->left = new node(15);
    root->left->right = new node(5);
    
    // root->levelOrderTraversal();
    // root->insert(12);
    // cout<<endl;
     root->levelOrderTraversal();
    // cout<<endl;
    root->reverseOrder();

	return 0;
}
