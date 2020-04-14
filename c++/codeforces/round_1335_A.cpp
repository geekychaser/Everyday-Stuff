#include<bits/stdc++.h>

using namespace std;
#define int long long
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";



int32_t main(){

fastIO 
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n <=2){
            cout<<"0"<<endl;
        }
        else{
            if(n&1){
                cout<<n/2<<endl;
            }else{
                cout<<((n/2) - 1)<<endl;
            }
        }
    }

}