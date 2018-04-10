#include <bits/stdc++.h>
using namespace std;



class derived2{
    
    
    public:
   
        
        void area(int x){
            cout<<x*x<<"  square \n";
        }
        
        void area(int r,int y){
            cout<<r*y<<" rectangle";
        }
    //cout<<"drived2 is called";
   
};

int main(){
    
    
    derived2 s;
    s.area(5);
    s.area(2,3);
    
    return 0;
}
