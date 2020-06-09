#include<bits/stdc++.h>

using namespace std;

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

}

set<int>arp;
set<pair<int,int>>bridges;
int n,m;

// to avoid repeating of number in articulation point due to every chid 
// we will take set


class Graph{
	unordered_map<int,list<int>>m;
	vector<int>discovey,low;
	int time;

public:

	Graph(){
		discovey.resize(n);
		low.resize(n);
		// time = 1;
	}

	void add_edge(int x,int y){
		m[x].push_back(y);
		m[y].push_back(x);
	}

	void dfs(int node,int parent){
		discovey[node] = low[node] = ++time;

		for(auto it: m[node]){
			if(discovey[it] == 0){
				dfs(it,node);

				low[node] = min(low[node],low[it]);

				if(parent!=-1 && low[it] >= discovey[node]){
					// if(it == 5)
					// cout<<parent<<" "<<low[it]<<" "<<discovey[node]<<endl;
					arp.insert(node);
				}

				if(low[it] > discovey[node]){
					bridges.insert({node,it});
				}
			}

			if(it != parent){
				low[node] = min(low[node],discovey[it]);
			}
		}

		// special case for parent node
		if(node == 0 && m[node].size() > 1){
			arp.insert(node);
		}
	}

	void articualtion(){

		dfs(0,-1);
	}

};



int main(){

	start();

	cin>>n>>m;

	Graph g;

	while(m--){
		int x,y;
		cin>>x>>y;

		g.add_edge(x,y);
	}

	g.articualtion();

	cout<<arp.size()<<endl;
	for(auto it: arp) cout<<it<<" ";

	cout<<endl<<bridges.size()<<endl;
	for(auto it: bridges){
		cout<<min(it.first,it.second)<<" "<<max(it.first,it.second)<<endl;
	}

}