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

void solve(string str,int i){
	if(str[i] == '\0') return;

	if(str[i] == str[i-2] && str[i]!=str[i-1]){
		ans++;
	}
	solve(str,i+1);
	
}



int32_t main(){
	fastIO
	// start();

	string str;
	cin>>str;

	solve(str,2);
	cout<<ans<<endl;

}