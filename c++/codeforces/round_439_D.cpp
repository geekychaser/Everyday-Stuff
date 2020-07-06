#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n";

int32_t main(){
    int n,m;
    cin>>n>>m;

    int a[n],b[m];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    sort(a,a+n);
    sort(b,b+m,greater<int>());
    int ans = 0;

    for(int i=0;i<min(n,m);i++){
        
        if(b[i] > a[i]){
            ans += b[i] - a[i];
        }
    }

    cout<<ans<<endl;

}