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

int solve(int n,int k){
	if(n == 0) return 1;

	if(n < 0) return 0;

	int ans = 0;
	for(int i=1;i<=k;i++){
		ans += solve(n-i,k);
	}

	return ans;
}


int32_t main(){
	fastIO
	// start();

	int n,k;
	cin>>n>>k;

	cout<<solve(n,k);

}