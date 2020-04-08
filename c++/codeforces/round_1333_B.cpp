#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n],b[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        map<int,bool>m;
        bool ans = true;

        for(int i=0;i<n;i++){
            if(b[i] - a[i] > 0 && m.find(1)==m.end()){
                ans = false;
            }
            else if(b[i] - a[i] < 0 && m.find(-1) == m.end()){
                ans = false;
            }

            m[a[i]] = true;
        }

        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}