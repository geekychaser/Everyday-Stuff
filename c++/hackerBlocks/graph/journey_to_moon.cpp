#include<bits/stdc++.h>

#define int long long
using namespace std;

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

}

class Graph{
	unordered_map<int,list<int>>m;

public:

	void add_edge(int x,int y,bool bidir = true){
		m[x].push_back(y);
		if(bidir) m[y].push_back(x);
	}

	void dfs_helper(int src,map<int,bool>&visited,int &count){
		count++;
		visited[src] = true;

		for(auto it: m[src]){
			if(!visited[it]){
				dfs_helper(it,visited,count);
			}
		}
	}

	int journey(int n){
		map<int,bool>visited;

		int total = n*(n-1) / 2;

		int count = 0;

		dfs_helper(0,visited,count);
		total -= (count * (count-1))/2;

		for(auto it: m){
			if(!visited[it.first]){
				count = 0;
				dfs_helper(it.first,visited,count);
				total -= (count * (count-1))/2;
			}
		}

		return total;
	}
};


int32_t main(){

	start();

	int n,p;
	cin>>n>>p;

	Graph g;

	for(int i=0;i<p;i++){
		int x,y;

		cin>>x>>y;

		g.add_edge(x,y);
	}

	cout<<g.journey(n)<<endl;

}