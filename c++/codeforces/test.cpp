#include<iostream>
#include<algorithm>

#define ll long long

using namespace std;

int main(){
    ll t;
    cin>>t;
    
    while(t--){
        ll n,b;
        cin>>n>>b;
        
        ll a[n];
        
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        
        sort(a,a+n);
        
        ll ans = 0;
        
        for(ll i=0;i<n;i++){
            if(b >= a[i]){
                b -= a[i];
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}