#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 5002

int dp[MAX][MAX];

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int n,m,k;
int *p;

int solve(int i,int count_k){

	if(i > n-m){
		// cout<<"mai chla "<<i<<endl;
		return 0;
	}

	if(count_k == k){
		// cout<<"mai bhi "<<count_k<<endl;
		 return 0;
	}

	if(dp[i][count_k] != -1) return dp[i][count_k];

	int op1 = 0,op2 = 0;

	for(int j=i;j<i+m;j++){
		// cout<<"andar "<<p[j]<<endl;
		op1 += p[j];
	}
	// cout<<"phele op1 "<<op1<<endl;
	op1 += solve(i+m,count_k+1);
	op2 = solve(i+1,count_k);
	// cout<<"op1 "<<op1<<" op2 "<<op2<<endl;
	dp[i][count_k] = max(op1,op2);
	return dp[i][count_k];
}



int32_t main(){
	// fastIO
	start();

	
	cin>>n>>m>>k;
	p = new int[n];

	for(int i=0;i<n;i++){
		cin>>p[i];
	}

	memset(dp,-1,sizeof(dp));

	cout<<solve(0,0)<<endl;



}