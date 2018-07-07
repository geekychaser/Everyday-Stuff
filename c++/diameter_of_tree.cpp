
#include<iostream>
#include<string>
#include<climits>


using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    
    node(int key){
        this->data = key;
        this->left = nullptr;
        this->right = nullptr;
    
    }
    
    int height(node* temp,int& diameter){
       // node* temp = this;
        
        if(temp == nullptr)
        return 0;
        
        else{
            
            int lh = height(temp->left,diameter);
            int rh = height(temp->right,diameter);
            
            diameter = ((lh + rh+1) > diameter ? lh+rh+1 : diameter);
            
            return((lh>rh)?lh+1:rh+1);
           //return (lh+rh+1);
        }
    }
    
    // int diameter(){
    //     node* temp = this;
        
    //     int h = height(temp);
        
        
        
        
    // }
};

int main(){
    int t,x;
    int diameter =INT_MIN;
    cin>>t>>x;
    int n =t-1;
    
    node* root = new node(x);
       
       for(int i=0;i<n;i++){
           node* test = root;
        string ch;
        int temp;
        
        cin>>ch;
       // cout<<ch<<endl;
        cin>>temp;
        
        
        for(auto it = ch.begin();it!=ch.end();it++){
            if(*it == 'L'){
                if(test->left == nullptr){
                    test->left = new node(temp);
                    
                }
                test = test->left;
            }
            
            if(*it == 'R'){
                if(test->right == nullptr){
                    test->right = new node(temp);
                    
                }
                test = test->right;
            }
            
        }
            
        }
 
    
    root->height(root,diameter);
    cout<<diameter;
}
