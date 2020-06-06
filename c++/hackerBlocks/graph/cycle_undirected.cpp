#include<bits/stdc++.h>

using namespace std;

#define ll long long

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

}

ll n,m;

class Graph{
	unordered_map<ll,list<ll>>m;

public:

	void add_edge(ll x,ll y,bool bidir = true){
		m[x].push_back(y);

		if(bidir)
			m[y].push_back(x);
	}

	bool dfs_helper(ll node, bool *visited,ll parent){
		visited[node] = true;

		for(auto it: m[node]){
			if(!visited[it]){
				bool cycle =  dfs_helper(it,visited,node);
				if(cycle) return true;
			}
			else if(it!=parent){
				return true;
			}
		}

		return false;
	}


	bool cycle(){

		bool * visited = new bool[n+1];

		for(int i=0;i<=n;i++){
			visited[i] = false;
		}


		for (int u = 0; u < n; u++) 
        if (!visited[u]) // Don't recur for u if it is already visited 
          if (dfs_helper(u,visited,-1)) 
             return true; 

		return false;
	}

};

int main(){

	start();

	ll t;
	cin>>t;

	while(t--){

		Graph g;

		cin>>n>>m;

		while(m--){
			ll x,y;
			cin>>x>>y;

			g.add_edge(x,y);
		}

		cout<<g.cycle()<<endl;
	}
}