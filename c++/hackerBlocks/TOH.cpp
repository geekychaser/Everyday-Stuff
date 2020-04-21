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

int ans = 0;

void solve(int n,string src,string helper,string dest){
	if(n == 0) return;

	solve(n-1,src,dest,helper);
	cout<<"Move "<<n<<"th"<<" disc"<<" from "<<src<<" to "<<dest<<endl;
	ans++;
	solve(n-1,helper,src,dest);
}



int32_t main(){
	fastIO
	// start();

	int n;
	cin>>n;
	string src = "T1";
	string dest = "T2";
	string helper = "T3";

	solve(n,src,helper,dest);
	cout<<ans<<endl;

}