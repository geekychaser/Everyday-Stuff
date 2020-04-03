#include<bits/stdc++.h>

#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";


using namespace std;

int32_t main(){
    int n,f;
    cin>>n>>f;

    string s;
    cin>>s;

    map<char,int>m;

    for(int i=0;i<n;i++){
        m[s[i]]++;
    }

    bool flag = true;

    for(auto it: m){
        // if(it.first % f!=0){
            // cout<<it.first<<endl;
            if(it.second > f){
                // cout<<f<<endl;
                flag = false;
            }
        // }
    }

    if(flag) cout<<"YES\n";
    else cout<<"NO\n";

}