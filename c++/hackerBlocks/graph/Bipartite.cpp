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

int n;

class Graph{
	unordered_map<int,list<int>>m;
	int * this_color;
public:
	void add_edge(int x,int y){
		m[x].push_back(y);
		m[y].push_back(x);
	}

	void dfs(int node,int parent,int color,bool &bip){
		this_color[node] = color;

		for(auto it: m[node]){
			if(this_color[it] == 0){
				dfs(it,node,3-color,bip);
			}
			else if(it != parent && color == this_color[it]){
				bip = false;
			}
		}
	}

	bool bipartite(){
		this_color = new int[n+1]{0};
		bool bip = true;

		dfs(1,0,1,bip);

		return bip;
	}
};


int main(){

	start();

	
		int m;
		
		cin>>n>>m;

		Graph g;

		while(m--){
			int x,y;
			cin>>x>>y;

			g.add_edge(x,y);
		}

		if(g.bipartite())cout<<"bipartite"<<endl;
		else cout<<"NOt a bipartite"<<endl;

}