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

vector<string>v;

void solve(string str,string out){
	if(str.size() == 0){
		v.push_back(out);
		return;
	}

	int digit = str[0] - '0';
	char temp= digit + 'a' - 1;
	solve(str.substr(1),out+temp);

	if(str.size() >= 2){
		int digit = (str[0] - '0')*10 + (str[1] - '0');
		if(digit <= 26){
			char temp = digit + 'a' - 1;
			solve(str.substr(2),out+temp);
		}
	}

}


int32_t main(){
	fastIO
	// start();

	string str;
	cin>>str;

	cout<<"[";
    solve(str, "");
	for(int i=0;i<v.size();i++){
		if(i == v.size()-1)cout<<v[i];
		else cout<<v[i]<<", ";
	}
	cout<<"]";
	

}