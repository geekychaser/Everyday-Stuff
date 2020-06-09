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
// set<pair<int,int>>bridges;
int n,s;
unordered_map<int,list<int>>m;

// to avoid repeating of number in articulation point due to every chid 
// we will take set


class Graph{
	
	vector<int>discovey,low;
	int time;

public:

	Graph(){
		discovey.resize(n);
		low.resize(n);
		// time = 0;
	}

	void add_edge(int x,int y){
		m[x].push_back(y);
		m[y].push_back(x);
	}

	void dfs(int node,int parent){

		int childern = 0;
		discovey[node] = low[node] = ++time;
		// cout<<"node hai "<<node<<endl;
		for(auto it: m[node]){

			if(discovey[it] == 0){
				childern++;
				dfs(it,node);

				low[node] = min(low[node],low[it]);
				if(parent == 0 && childern > 1){
					arp.insert(node);
				}

				if(parent!=0 && low[it] >= discovey[node]){
					// if(it == 5)
					// cout<<parent<<" "<<low[it]<<" "<<discovey[node]<<endl;
					arp.insert(node);
				}

				// if(low[it] > discovey[node]){
				// 	bridges.insert({node,it});
				// }
			}

			if(it != parent){
				low[node] = min(low[node],discovey[it]);
			}
		}

		// special case for parent node
		
	}

	void articualtion(){

		dfs(1,0);

		for(auto it: m){
			if(discovey[it.first] == 0){
				dfs(it.first,0);
			}
		}
		// if(discovey[19] == 0)cout<<"gadbad";
		// for(auto it: discovey) cout<<it<<" ";
	}

};



int main(){

	start();

	cin>>n>>s;

	Graph g;

	while(s--){
		int x,y;
		cin>>x>>y;

		g.add_edge(x,y);
	}

	g.articualtion();

	

	int q;
	cin>>q;

	while(q--){
		int k;
		cin>>k;

		if(arp.find(k) != arp.end()) cout<<"Satisfied "<<m[k].size()<<endl;
		else cout<<"Not Satisfied"<<endl;
	}

	// cout<<arp.size()<<endl;
	// for(auto it: arp) cout<<it<<" ";

	// cout<<endl<<bridges.size()<<endl;
	// for(auto it: bridges){
	// 	cout<<min(it.first,it.second)<<" "<<max(it.first,it.second)<<endl;
	// }

}