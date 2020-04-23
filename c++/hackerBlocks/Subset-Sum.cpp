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

int counter = 0;
vector<vector<int>>ans;
void solve(int n,int m,int i,int j,string ans){

	if(j == n) return;

	if(sum == target){
		counter++;
		ans.push_back(temp);
		return;
	}

	for(int i=0;i<n;i++){
		solve(n,v,temp.push_back(v[i]),sum+v[i]);
	}
	
}



int32_t main(){
	fastIO
	// start();
	int n;
	cin>>n;

	vector<int>v(n);

	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	int target;
	cin>>target;

	solve()


}