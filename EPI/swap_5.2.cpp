#include<iostream>
using namespace std;

int swap(long x,int i,int j){
    if(((x >> i)&1) != ((x >> j)&1) ){
        x = x^((1 << i) | (1 << j));
    }

    return x;
}

int main(){
    long x=12;
    int i=1;
    int j=2;

    x = swap(x,i,j);

    cout<<x<<endl;
}