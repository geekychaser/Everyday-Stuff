#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1000002

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int k;
string a;


void solve(){
	int sum[MAX] = {0};
	sum[0] = 1;
	int s = 0;
	int ans = 0;

	for(int i=0;i<a.length();i++){
		s += a[i] - '0';
		if(s >= k) ans += sum[s-k];
		sum[s]++;
	}

	cout<<ans<<endl;
}



int32_t main(){
	// fastIO
	start();
	
	cin>>k;
	cin>>a;

	solve();



}