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

	int n,m;
	char check;
	cin>>n>>m;
	cin>>check;

	char c[n][m];

	vector<pair<int,int> >v;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c[i][j];
			if(c[i][j] == check)v.push_back(make_pair(i,j));
		}
	}

	map<char,bool>ans;

	for(auto it: v){

		if(it.first - 1 >= 0){
			ans[c[it.first-1][it.second]] = true;
		}

		if(it.first + 1 <= n-1){
			ans[c[it.first+1][it.second]] = true;
		}

		if(it.second - 1 >= 0){
			ans[c[it.first][it.second - 1]] = true;
		}

		if(it.second + 1 <= m-1){
			ans[c[it.first][it.second + 1]] = true;
		}
	}

	// for(auto it: ans)cout<<it.first<<" ";
	// 	cout<<endl;
	
	ans.erase('.');
	ans.erase(check);
	cout<<ans.size()<<endl;
}