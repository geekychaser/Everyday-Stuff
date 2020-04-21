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

void solve(char *str,char *out,int i,int j){
	if(str[i] == '\0'){
		out[j] = '\0';
		cout<<out<<" ";
		ans++;
		return;
	}

	solve(str,out,i+1,j);
	out[j] = str[i];
	solve(str,out,i+1,j+1);

	int val = 97 + str[i] - 'a';
	out[j] = (val/10) + '0';
	out[j+1] = (val%10) + '0';
	solve(str,out,i+1,j+2);
}

// void solve(char *s, char* out,int i,int j){
// 	if(s[i] == '\0'){
// 		out[j] = '\0';
// 		cout<<out<<" ";
// 		ans++;
// 		return;
// 	}

// 	solve(s,out,i+1,j);
// 	out[j] = s[i];
// 	solve(s,out,i+1,j+1);
// }


int32_t main(){
	fastIO
	// start();

	char str[MAX];
	cin>>str;

	char out[MAX];

	solve(str,out,0,0);

	cout<<endl<<ans<<endl;
	

}