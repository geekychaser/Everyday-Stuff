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

void solve(int n,int *a,int i,int k){
	if(i+k >= n){
		return;
	}

	int temp = a[i];
	for(int j=i+1;j<k;j++){
		temp = temp^a[j];
		cout<<"temp "<<temp<<endl;
	}
	cout<<"temp now when i is "<<i<<" "<<temp<<endl;
	sum = max(sum,temp);

	solve(n,a,i+1,k);
}



int32_t main(){
	fastIO
	start();

	int test;
	cin>>test;
	// int t=0;

	while(test--){
		// t++;
		int n,k;
		cin>>n>>k;

		int a[n];

		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		sum = 0;
		solve(n,a,0,k);
		cout<<sum<<endl;
	}

	



	


}