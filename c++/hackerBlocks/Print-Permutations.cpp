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

int counter = 0;

void solve(char *s, int i){
	if(s[i] == '\0'){
		cout<<s<<" ";
		return;
	}

	for(int j=i;s[j]!='\0';j++){
		swap(s[i],s[j]);
		solve(s,i+1);
		swap(s[i],s[j]);
	}
}

int32_t main(){
	fastIO
	// start();

	char s[7];
	cin>>s;

	solve(s,0);

}