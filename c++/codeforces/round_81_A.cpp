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

int32_t main(){
	fastIO
	start();

	string s;
	cin>>s;

	stack<char>st;

	for(int i=0;i<s.length();i++){
		if(st.empty() || st.top()!= s[i]){
			st.push(s[i]);
		}else{
			while(!st.empty() && st.top() == s[i]){
				st.pop();
			}
		}
	}

	string ans = "";
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}

	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;

}