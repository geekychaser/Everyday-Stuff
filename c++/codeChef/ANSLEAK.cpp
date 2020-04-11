#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        vector< vector<int> >v(n,vector<int>(k));

        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                cin>>v[i][j];
            }
        }

        for(int i=0;i<n;i++){
            cout<<v[i][i/2]<<endl;
        }
    }
}