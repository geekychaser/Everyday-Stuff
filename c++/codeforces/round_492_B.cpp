#include<bits/stdc++.h>

using namespace std;


#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";

int32_t main(){
    IOS
    int n,l;
    cin>>n>>l;

    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    double case1 = (double)v[0];
    int diff = 0;

    for(int i=1;i<n;i++){
        diff = max(v[i] - v[i-1], diff);
    }

    double case2 = (double)diff/(double)2;
    double case3 = (double) (l - v[n-1]);

    double ans = (double)max(case3,max(case1,case2));

    cout<<setprecision(10);
    cout<<ans<<endl;
}