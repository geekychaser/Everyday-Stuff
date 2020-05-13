#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 2001

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int n,t;
double p;
double dp[MAX][MAX] = {0};

double solve(){
	dp[0][0] = 1;

	for(int i=1;i<=t;i++){
		for(int j=0;j<=n;j++){
			if(j == n){
				dp[i][j] += dp[i-1][j] + p*dp[i-1][j-1];
			}
			else if(j == 0){
				dp[i][j] = (1-p)*dp[i-1][j];
			}
			else{
				dp[i][j] += p*dp[i-1][j-1];
				dp[i][j] += (1-p)*dp[i-1][j];
			}
		}
	}

	double ans  = 0;
	for(int i=0;i<=n;i++){
		// cout<<dp[t][i]<<"  ";
		ans += i*dp[t][i];
	}

	return ans;
}



int32_t main(){
	// fastIO
	start();
	
	cin>>n>>p>>t;

	cout<<fixed<<setprecision(8)<<solve()<<endl;



}