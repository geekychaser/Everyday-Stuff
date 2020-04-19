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

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void solve(char *in,char *out,int i,int j){
	if(in[i] == '\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}

	string temp = table[in[i] - '0'];
	// cout<<temp<<endl;
	for(int k=0;k<temp.length();k++){
		out[j] = temp[k];
		solve(in,out,i+1,j+1);
	}
}


int32_t main(){
	fastIO
	// start();

	char s[100];
	char temp[100] ;
	cin>>s;
	

	solve(s,temp,0,0);

}