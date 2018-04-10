#include<iostream>
using namespace std;

class base1{
    
    public:
    base1(){
        cout<<"base is called";
    }
};

class base2{
    
    public:
    base2(){
        cout<<"base2 is called";
    }
};

class derived : public base1,public base2{
    
    public:
    derived(){
        cout<<"derived is called";
    }
    
};

int main(){
    
    derived d;
}
