#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100001
int shift = 100002;

int dp[101][MAX];

int *taste;
int *calorie;
int n,k;

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int solve(int i,int sum){
	if(i == n){
		if(sum == 0) return 0;
		else return -1e12;
	}

	if(dp[i][sum+shift] != -1) return dp[i][sum+shift];

	int op1 = solve(i+1,(taste[i] - k*calorie[i]) + sum) + taste[i];
	int op2 = solve(i+1,sum);

	dp[i][sum+shift] = max(op1,op2);


	return dp[i][sum+shift];
}



int32_t main(){
	// fastIO
	start();

	cin>>n>>k;

	taste = new int[n];
	calorie = new int[n];

	for(int i=0;i<n;i++){
		cin>>taste[i];
	}

	for(int i=0;i<n;i++){
		cin>>calorie[i];
	}

	memset(dp,-1,sizeof(dp));

	int ans = solve(0,0);
	if(ans) cout<<ans<<endl;
	else cout<<"-1"<<endl;




}