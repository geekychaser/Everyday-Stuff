#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int32_t main(){

    int n;
    cin>>n;

    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int>b = a;

    sort(b.begin(),b.end());

    for(int i=1;i<n;i++){
        a[i] = a[i]+a[i-1];
        b[i] = b[i] + b[i-1];
    }

    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }

    int q;
    cin>>q;
    // cout<<endl;

    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        l--;r--;

        if(type == 1){
            // cout<<a[r]<<" "<<a[l]<<"    ";
            if(l-1 >=0 )
            cout<<a[r]-a[l-1]<<endl;
            else cout<<a[r]<<endl;
        }
        else{
            if(l-1 >=0)
            cout<<b[r]-b[l-1]<<endl;
            else cout<<b[r]<<endl;
        }
    }

}