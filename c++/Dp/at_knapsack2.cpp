//recurive code hai 0/1 knapsack ka
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;
#define int long long
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define MAX 100001

void start(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

}

int dp[101][MAX];
int *wt,*val;

int memoization(int capacity,int n,int profit){
    if(profit == 0 && n == 0){
        return 0;
    }

    if(n == 0) return 1e11;

    if(val[n])
}

int solve(int capacity,int n,int profit){
    

    for(int i=0;i<=n;i++){
    	for(int j=0;j<=profit;j++){
    		if(i == 0 && j == 0) dp[i][j] = 0;
    		else if(i == 0) dp[i][j] = 1e11;
    		else if(j >= val[i-1]){
    			dp[i][j] = min(wt[i-1] + dp[i-1][j-val[i-1]],dp[i-1][j]);
    		}
    		else dp[i][j] = dp[i-1][j];
    	}
    }

    int ans = 0;

    for(int i=0;i<=profit;i++){
    	if(dp[n][i] <= capacity) ans = i;
    }

    return ans;

} 


int32_t main(){
// start();
fastIO 

int n,capacity;
cin>>n>>capacity;

wt = new int[n];
val = new int[n];
int profit = 0;

for(int i=0;i<n;i++){
    cin>>wt[i];
    cin>>val[i];
    profit += val[i];
}
// memset(dp,-1,sizeof(dp));
// cout<<knapsack(wt,val,capacity,n)<<endl;
// cout<<memoization(wt,val,capacity,n)<<endl;
memset(dp,0,sizeof(dp));
cout<<solve(capacity,n,profit)<<endl;


}