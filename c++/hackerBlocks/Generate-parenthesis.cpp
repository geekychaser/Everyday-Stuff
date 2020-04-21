#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}


void solve(int n,int i,int j,string ans){

	if(j == n && i == n){
		cout<<ans<<endl;
		return;
	}

	if(i > j){
		// ans += ")";
		 solve(n,i,j+1,ans+')');
	}

	if(i < n){
		// ans += "(";
		solve(n,i+1,j,ans+'(');
	}
	
}



int32_t main(){
	fastIO
	// start();
	string ans = "";

	int n;
	cin>>n;

	solve(n,0,0,ans);


}