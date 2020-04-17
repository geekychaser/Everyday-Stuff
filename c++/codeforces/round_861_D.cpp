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

	int n;
	cin>>n;

	vector<string>v(n);
	map<string,int>m;

	for(int i=0;i<n;i++){
		cin>>v[i];

		set<string>s;

		for(int j=0;j<9;j++){
			string temp = "";
			for(int k=j;k<9;k++){
				temp += v[i][k];
				s.insert(temp);
			}
		}

		for(auto it: s){
			m[it]++;
		}
	}

	vector<string>ans(n);

	for(int i=0;i<n;i++){

		for(int j=0;j<9;j++){
			string temp = "";
			for(int k=j;k<9;k++){
				temp += v[i][k];

				if(m[temp] == 1){
					if(ans[i].size() == 0) ans[i] = temp;
					else if(ans[i].size() > temp.size()) ans[i] = temp;
				}
			}
		}
	}

	for(auto it: ans)cout<<it<<endl;

}