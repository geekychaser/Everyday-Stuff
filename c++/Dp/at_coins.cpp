#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

double p[3001];
double dp[3001][3001];

double solve(int coins,int head){
	if(head <= 0){
		return 1;
	}

	if(coins ==  0) return 0;

	if(dp[coins][head] > -1) return dp[coins][head];

	double op1 = p[coins] * solve(coins-1,head-1);
	double op2 = (1 - p[coins])*solve(coins-1,head);

	dp[coins][head] = op1+op2;

	return op1+op2;
}



int32_t main(){
	fastIO
	start();

	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;

	for(int i=1;i<=n;i++) cin>>p[i];

	cout<<fixed<<setprecision(11)<<solve(n,(n+1)/2);

	// it is said that we need more heads than tails so i 
	// opted for n+1/2 heads

}