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

int ans = INT_MAX;

void solve(vector<int>v,int start,int n,bool visited[],int steps){
	if(start == n){
		ans = min(ans,steps);
		return;
	}

	visited[start] = true;

	if(start+1<=n && !visited[start+1]){
		solve(v,start+1,n,visited,steps+1);
	}

	if(start+v[start] >= 0 && start+v[start] <= n && !visited[start+v[start]]){
		solve(v,start+v[start],n,visited,steps+1);
	}

	visited[start] = false;
	return;
}



int32_t main(){
	fastIO
	start();

	int test;
	cin>>test;
	// int t=0;

	while(test--){
		// t++;
		int n;
		cin>>n;
		ans = INT_MAX;
		bool visited[100000] = {0};

		vector<int>a(n+1);

		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		solve(a,0,n,visited,0);
		cout<<ans<<endl;
	}

	



	


}