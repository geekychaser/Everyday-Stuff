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

	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		if(s.length() > 10){
			cout<<s[0]<<s.length()-2<<s[s.length()-1]<<endl;
		}
		else{
			cout<<s<<endl;
		}
	}

}