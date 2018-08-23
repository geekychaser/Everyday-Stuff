#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* head ;

void insert(int val){
    Node* temp;
    temp = new Node;
    temp->next = nullptr;
    temp->data = val;
    temp->next = head;
    head = temp;
}

void print(){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
        cout<<temp->data<<endl;
        //cout<<"print chla";
    }
    
    
}

int main() {
    head = nullptr;
	int n=4;

	for(int i=1;i<=n;i++){
	   // int k;
	   // cin>>k;
	    //cout<<"chla";
	    insert(i);
	   
	}
	
	cout<<"printing";
	 print();
	 
	return 0;
}
