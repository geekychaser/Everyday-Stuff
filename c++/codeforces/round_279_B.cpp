#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n,t;
    cin>>n>>t;

    ll a[n];

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

   ll i=0,j=0;
   ll ans = 0, count = 0;

   while(i < n && j < n){

       if(t - a[j] >= 0){
           count++;
           ans = max(count,ans);
           t = t -a[j];
           j++;
       }
       else{
           t = t + a[i];
           i++;
           count--;
       }
   }

    cout<<ans<<"\n";
}