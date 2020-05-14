#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[1002][1002] ;
vector<vector<int>>ans;
bool solve(int *a,int n,int k,vector<int>v){
    if(k == 0){
        ans.push_back(v);
        return 1;
    }
    if(n == 0) return 0;

    if(dp[n][k] != -1) return dp[n][k];

    if(a[n-1] <= k){
        bool op1 = solve(a,n-1,k,v);
        v.push_back(a[n-1]);
        bool op2 = solve(a,n-1,k-a[n-1],v);
        v.pop_back();

        return dp[n][k] = op1 || op2;
    }
    else{
        return dp[n][k] = solve(a,n-1,k,v);
    }
}

int32_t main(){
    // int t;
    // cin>>t;

    // while(t--){
        int n,k;
        cin>>n>>k;

        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        // cin>>k;
        // sort(a,a+n);
        // vector<int>v;
        // memset(dp,-1,sizeof(dp));

        // solve(a,n,k,v);
        // for(auto it: ans){
        //     sort(it.begin(),it.end());
        //     for(auto i: it){
        //         cout<<i<<" ";
        //     }
        //     cout<<" ";
        // }

        // cout<<endl<<ans.size()<<endl;


        bool dp[1002][1002] = {0};

        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=k;i++){
            dp[0][i] = 0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){

                if(a[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i-1]];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }



        cout<<dp[n][k]<<endl;
    }

}