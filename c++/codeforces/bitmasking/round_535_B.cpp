#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 2001
#define mod 1000000007

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}


string n;

int solve(){

	int len = n.size();

	int d = (1<<d) - 2;
	int ans = d;
	int pos = 0;
	for(int i=len-1;i>=0;i--){
		if(n[i] == 7){
			ans += (1<<pos);
		}
		pos++;
	}

	cout<<ans+1<<endl;

}



int32_t main(){
	// fastIO
	start();
	
	cin>>n;

	solve();


}