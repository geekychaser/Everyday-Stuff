#include<iostream>
#include<vector>
using namespace std;

void primes(int n){
    vector<bool>v(n+1,true);

    for(int i=2;i*i<=n;i++){
        if(v[i]){
            for(int j=2*i ; j<=n ; j+=i){
                v[j] = false;
            }
        }
    }

    for(int i=2;i<=n;i++){
       if(v[i])
       cout<<i<<" ";
    }

}

int main(){
    primes(20);
}