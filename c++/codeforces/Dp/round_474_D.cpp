#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100002
#define mod 1000000007

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int t,k;
int dp[MAX];
int pre[MAX] = {0};

int solve(int len){
	if(len == 0) return 1;

	if(dp[len] != -1) return dp[len];
	int op1 = 0,op2 = 0;

	op1 = solve(len-1) ;

	if(len >= k){
		op2 = solve(len-k) ;
	}
	// cout<<op1+op2<<endl;
	dp[len] = (op1+op2)%mod;

	return (op1+op2)%mod;
}

void precompute(){
	memset(dp,-1,sizeof(dp));
	pre[0] = 0;

	for(int i=1;i<=100000;i++){
		// cout<<p[i]<<endl;
		// cout<<solve(i)<<endl;
		pre[i] = pre[i-1] + solve(i);
		pre[i] %= mod;
		// cout<<pre[i]<<endl;
	}

	// for(int i=0;i<=100000;i++){
	// 	cout<<pre[i]<<endl;
	// }

	// cout<<pre[3]<<" "<<pre[1]<<endl;
}

int32_t main(){
	fastIO
	start();

	cin>>t>>k;
	precompute();

	while(t--){

		int a,b;
		cin>>a>>b;

		// for(int i=a;i<=b;i++){
		// 	// cout<<i<<endl;
		// 	ans += solve(i);
		// }
		// cout<<pre[b]<<" "<<pre[a-1]<<endl;
		cout<<(pre[b] - pre[a-1] + mod)%mod<<endl;
		// yha pe + mod isley kiyahai kyuki kahi val negative na ho jaay
		// kyuki humne pre mai har baari mod krke save kia h value ko
		// +mod ni kroge toh test ase 3 se hi WA aa jayega

	}

}