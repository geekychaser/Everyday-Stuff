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

void solve(char *s, char* out,int i,int j){
	if(s[i] == '\0'){
		out[j] = '\0';
		cout<<out<<" ";
		counter++;
		return;
	}

	solve(s,out,i+1,j);
	out[j] = s[i];
	solve(s,out,i+1,j+1);
}

int32_t main(){
	fastIO
	// start();

	char s[1000],out[1000];
	cin>>s;

	solve(s,out,0,0);
	cout<<endl<<counter<<endl;

}