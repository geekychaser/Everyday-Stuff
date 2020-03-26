#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n,k;
        cin>>n>>k;

        if(n >= k*k && n%2 == k%2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}