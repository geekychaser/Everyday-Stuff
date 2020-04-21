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

int counter = 0;

void solve(int n,int m,int i,int j,string ans){

	if(i == n-1 && j == m-1){
		cout<<ans<<" ";
		counter++;
		return;
	}

	if(i+1 < n){
		// ans += "(";
		solve(n,m,i+1,j,ans+'V');
	}

	if(j+1 < n){
		 solve(n,m,i,j+1,ans+'H');
	}

	if(i+1 < n && j+1 < m){
		solve(n,m,i+1,j+1,ans+'D');
	}
	
}



int32_t main(){
	fastIO
	// start();
	string ans = "";

	int n,m;
	cin>>n>>m;

	solve(n,m,0,0,ans);
	cout<<endl<<counter<<endl;


}