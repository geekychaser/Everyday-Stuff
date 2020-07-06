#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n;
    cin>>n;

    ll a[n];

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans = 1;
    ll max = a[0];
    ll min = a[0];
    for(int i=1;i<n;i++){
        if(a[i] > max){
            max = a[i];
            ans++;
        }else{
            ans = 1;
            continue;
        }
    }

    cout<<ans<<endl;
}