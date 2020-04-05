#include<bits/stdc++.h>

#define int long long
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";


using namespace std;

int32_t main(){
    fastIO

    int n,m;
    cin>>n>>m;

    vector<int>v;

    int a,b;
    int temp = 0;

    for(int i=0;i<n;i++){
        cin>>a>>b;
        temp += a*b;
        v.push_back(temp);
    }

    int moment[m];

    for(int i=0;i<m;i++){
        cin>>moment[i];
    }

    for(int i=0;i<m;i++){
        cout<<lower_bound(v.begin(),v.end(),moment[i])-v.begin() + 1<<"\n";
    }


}