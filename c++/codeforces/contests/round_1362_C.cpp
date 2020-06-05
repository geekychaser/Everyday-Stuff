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

bool check(int k,unordered_map<int,bool>m,int *a,int n){

	for(int i=0;i<n;i++){
		if(m[a[i] ^ k] == false) return false;
	}

	return true;
}

int32_t main(){
	// fastIO
	start();

	int t;
	cin>>t;

	while(t--){
		int ans = 0;
		int n;
		cin>>n;

		while(n){
			ans += n;
			n = n/2;
		}

		cout<<ans<<endl;
	}
}