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



int32_t main(){
	fastIO
	start();

	int n;
	cin>>n;

	map<int,vector<int>>m;
	priority_queue<int>q;
	vector<int>v(n);

	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	int temp;

	for(int i=0;i<n;i++){
		cin>>temp;
		m[v[i]].push_back(temp);
	}

	int ans = 0;
	int res = 0;
	// sort(v.begin(),v.end());
	// v.erase(unique(v.begin(),v.end()),v.end());
	set<int>s(v.begin(),v.end());

	for(auto it: s){
		if(m[it].size()>1 || !q.empty()){
			for(int i=0;i<m[it].size();i++){
				q.push(m[it][i]);
				ans += m[it][i];
			}

			ans -= q.top();
			q.pop();

			int now = it;

			while(!q.empty()){
				res += ans;
				now++;
				if(m[now].size()) break;
				else{
					ans -= q.top();
					q.pop();
				}
			}
		}
	}

	cout<<res<<endl;

}