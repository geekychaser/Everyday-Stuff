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


bool solve(string str,int i,vector<char>s){
	if(str[i] == '\0' && s.empty()){
		cout<<i<<endl;
		return true;
	}

	if(str[i] == '(' || str[i] == '{' || str[i] == '['){
		s.push_back(str[i]);
	}

	else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
		if(!s.empty() && s[s.size()-1] == str[i]){
			s.pop_back();
		}
		else return false;
	}
	
	return solve(str,i+1,s);

}


int32_t main(){
	fastIO
	// start();

	string str;
	cin>>str;
	vector<char>s;

	if(solve(str,0,s))cout<<"true"<<endl;
	else cout<<"false"<<endl;
	

}