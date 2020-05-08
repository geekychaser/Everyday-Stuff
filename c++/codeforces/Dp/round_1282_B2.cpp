#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100001
int shift = 100002;

int n,p,k;
int *cost;


void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int solve(int i,int sum){

}



int32_t main(){
	// fastIO
	start();

	int t;
	cin>>t;

	while(t--){

		cin>>n>>p>>k;

		cost = new int[n];

		for(int i=0;i<n;i++){
			cin>>cost[i];
		}

		sort(cost,cost + n);

		int dp[n+1] = {0};
		dp[0] = cost[0];

		int ans = 0;
		if(dp[0] <= p) ans = 1;

		for(int i=1;i<k;i++){
			if(i == k-1)dp[i] = cost[i];
			else dp[i] = dp[i-1] + cost[i];
			if(dp[i] <= p) ans = i+1;
		}

		

		for(int i=k;i<n;i++){
			dp[i] = cost[i] + dp[i-k];

			if(dp[i] <= p) ans = i+1;
		}

		cout<<ans<<endl;
	}



}