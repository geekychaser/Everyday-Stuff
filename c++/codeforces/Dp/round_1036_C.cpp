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


int dp[20][4][2];
string s;
// this one is digit dp solution 
int solve(int pos,int count,bool tight){

	if(pos == s.length()){
		return 1;
	}

	if(dp[pos][count][tight] != -1){
		return dp[pos][count][tight];
	}

	int end = ((tight)?(s[pos] - '0'):9);
	int ans = 0;
	for(int i=0;i<=end;i++){
		int cnt = count + (i>0);
		if(cnt <= 3)
		ans += solve(pos+1,cnt,tight&(i == end));
	}

	return dp[pos][count][tight] = ans;


}
	

// greedy solution where we precompute all possible ans and binary search on set




int32_t main(){
	// fastIO
	start();
	
	int t;
	cin>>t;

	while(t--){
		int l,r;
		cin>>l>>r;

		memset(dp,-1,sizeof(dp));
		s = to_string(r);
		int ans = solve(0,0,1);

		memset(dp,-1,sizeof(dp));
		l-=1;
		s = to_string(l);
		ans -= solve(0,0,1);

		cout<<ans<<endl;


	}



}