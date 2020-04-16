#include<bits/stdc++.h>

#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define mod 1000000007


using namespace std;

int32_t main(){
IOS
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        sort(v.begin(),v.end(),greater<int>());

        int profit = 0;
        int diff = 0;
        for(int i=0;i<n;i++){
            profit += max(v[i]-diff,(long long)0);
            profit = profit%mod;
            diff++;
        }

        cout<<profit%mod<<"\n";
    }
}