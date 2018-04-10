#include<iostream>
using namespace std;

class base{
    
    public:
    base(){
        cout<<"base is called";
    }
};

class derived : public base{
    
};

int main(){
    
    derived d;
}
