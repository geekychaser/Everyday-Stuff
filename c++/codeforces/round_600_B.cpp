#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll n,m;
    cin>>n>>m;

    vector<int>a(n);
    vector<int>b(m);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());
    
    int ans[m];

    for(int i=0;i<m;i++){
        cin>>b[i];
        ans[i] = upper_bound(a.begin(),a.end(),b[i]) - a.begin();
    }

    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }

}