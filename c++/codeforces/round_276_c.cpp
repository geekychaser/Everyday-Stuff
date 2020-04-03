#include<bits/stdc++.h>

#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";


using namespace std;

int32_t main(){
    int n,q;
    cin>>n>>q;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n,greater<int>());

    int x,y;
    vector<int>m(n);

    for(int i=0;i<q;i++){
        cin>>x>>y;
            m[x-1]++;
            if(y <= n-1)
                m[y]--;
    }

    int sum = 0;
    int ans = 0;
    // op(m,n);
    // cout<<endl;

    for(int j=0;j<n;j++){
        sum += m[j];
        m[j] = sum;
    }
    sort(m.begin(),m.end(),greater<int>());
    // op(m,n);
    // cout<<endl;
    for(int i=0;i<n;i++){
        ans += m[i]*a[i];
    }
    cout<<ans<<"\n";



}