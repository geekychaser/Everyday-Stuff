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
		int n;
		cin>>n;

		int a[n];

		unordered_map<int,bool>m;

		for(int i=0;i<n;i++){
			cin>>a[i];
			m[a[i]] = true;
		}

		bool flag = false;
		int i;
		for(i=1;i<=1024;i++){
			if(check(i,m,a,n)){
				flag = true;
				break;
			}
		}

		if(flag)cout<<i<<endl;
		else cout<<"-1"<<endl;

	}
}