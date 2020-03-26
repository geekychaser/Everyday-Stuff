#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll a,b;

        cin>>a>>b;
        
        if(a > b){
            ll temp = a/b;
            if(a%b == 0) cout<<"0"<<"\n";
            else cout<<b*(temp+1) - a<<"\n";
        }else{
            cout<<b-a<<"\n";
        }
    }
}