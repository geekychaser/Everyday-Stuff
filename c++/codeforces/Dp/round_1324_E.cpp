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

int p[2001];
int dp[2001][2001];
int n,h,l,r;
int ans = 0;

int solve(int i,int sleep){

	if(i == n) return 0;

	// if(sleep >= l && sleep <= r){
	// 	cout<<"sleep is "<<sleep<<endl;
	// 	ans++;
	// 	return;
	// }

	if(dp[i][sleep] != -1) return dp[i][sleep];
	int x = (sleep + p[i])%h;
	
	int y = (sleep + p[i]-1)%h;
	
	int op1 = solve(i+1,x);
	if(x >= l && x <= r) op1++;
	
	int op2 = solve(i+1,y);
	if(y >= l && y <= r) op2++;
	
	dp[i][sleep] = max(op1,op2);
	
	return max(op1,op2);
}



int32_t main(){
	fastIO
	start();

	memset(dp,-1,sizeof(dp));
	cin>>n>>h>>l>>r;

	for(int i=0;i<n;i++) cin>>p[i];
	
	cout<<solve(0,0)<<endl;
	
}