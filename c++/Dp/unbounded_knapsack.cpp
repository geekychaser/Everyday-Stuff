#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}



int32_t main(){
	fastIO
	start();

	int t;
	cin>>t;

	while(t--){
		int n,w;
		cin>>n>>w;

		int val[n],wt[n];

		for(int i=0;i<n;i++){
			cin>>val[i];
		}

		for(int i=0;i<n;i++){
			cin>>wt[i];
		}

		int dp[n+1][w+1];

		memset(dp,0,sizeof(dp));

		for(int i=1;i<=n;i++){
			for(int j=1;j<=w;j++){
				if(wt[i-1] <= j){
					dp[i][j] = max(val[i-1] + dp[i][j - wt[i-1]],dp[i-1][j]);
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}

		cout<<dp[n][w]<<endl;
	}
	

}