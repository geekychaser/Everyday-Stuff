#include<bits/stdc++.h>

#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";


using namespace std;

int32_t main(){

  IOS

  int t;
  cin>>t;

  while(t--){
    int n,x;
    cin>>n>>x;

    int a[n];
    map<int,bool>m;

    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]] = true;
    }

    sort(a,a+n);

    int count = 1;
    int ans = 0;
    int temp = x;

    // for(int i=1;i<=max(a[n-1],temp);i++){
    //     if(m.find(i)==m.end()){
    //         x--;
    //         m[i] = true;
    //         if(x == -1){
    //             ans = i-1;
    //             break;
    //         }
    //     }
    //     // ans = i;
    // }
    int i = 1;

    while(x!=-1){

        while(m.find(i)!=m.end()){
            ans = i;
            i++;
        }
        if(m.find(i) == m.end()){
            m[i] = true;
            x--;
            if(x >= 0)
            ans = i;
            i++;
        }
    }

    // for(auto it : m){
    //     cout<<it.first<<" ";
    // }

    cout<<ans<<"\n";
  }
}