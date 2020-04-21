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


void solve(int n, int a){
	if(a > n) return;
	cout<<a<<" ";

	int i = 0;
	if(a == 0) i = 1;

	for(;i<=9;i++){
		solve(n,10*a+i);
	}


}


int32_t main(){
	fastIO
	// start();

	int n;
	cin>>n;


	solve(n,0);
	

}