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

set<string>sol;

void solve(string in,int l,int r){
	if( l== r){
		sol.insert(in);
		return;
	}

	for(int i=l;i<=r;i++){
		swap(in[i],in[l]);
		solve(in,l+1,r);
		swap(in[i],in[l]);
	}


}


int32_t main(){
	fastIO
	start();

	string s;
	cin>>s;

	solve(s,0,s.size()-1);

	for(auto it: sol){
		cout<<it<<endl;
	}


}