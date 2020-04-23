#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define trick -1

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}
int sum = 0;

void solve(int n,int *a,int i){
	if(i == n){
		return;
	}


	sum += a[i];

	solve(n,a,i+1);
}



int32_t main(){
	fastIO
	start();

	int test;
	cin>>test;
	int t=0;

	while(test--){
		t++;
		int n;
		cin>>n;

		int a[n];

		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		sum = 0;
		solve(n,a,0);
		cout<<"Case "<<t<<": "<<sum<<endl;
	}

	



	


}