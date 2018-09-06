#include<iostream>
using namespace std;

int gcd(int a,int b){

    if(a == b)
    return a;

    else if(a==0)
    return b;

    else if(b==0)
    return a;

    if(~a&1){  //if a is even
        if(b&1){
             return gcd((a>>1),b);
        }
        // else if(a>b){
        //         return gcd(((a-b)>>1),b);
        // }
        //     else if(b>a)
        //         return gcd(a,((b-a)>>1));
         else 
        return gcd((a>>1),(b>>1)) << 1;

    }

    else if(~b&1){
        if(a&1){
           
            return gcd(a,(b>>1));
        }
        // else if(a>b){
        //         return gcd(((a-b)>>1),b);
        // }
        //     else if(b>a)
        //         return gcd(a,((b-a)>>1));
         else 
        return gcd((a>>1),(b>>1)) << 1;

    }

    else if(a>b){
        return gcd(((a-b)>>1),b);
        }
    else if(b>a)
        return gcd(a,((b-a)>>1));

    
}

int main(){
    int a=24,b=10;
    int c = gcd(a,b);
    cout<<c<<endl;
}