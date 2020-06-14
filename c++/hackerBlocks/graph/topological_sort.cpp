// can only be applicable in dircted non-cyclic graph
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
	vector<int>ans;

public:

	void add_edge(int x,int y){
		m[x].push_back(y);
		// m[y].push_back(x);
	}

	void dfs(int node,bool *visited){

		visited[node] = true;
		for(auto it:m[node]){
			if(!visited[it])
				dfs(it,visited);
		}

		ans.push_back(node);
	}

	vector<int> topological_sort_dfs(){
		bool *visited = new bool[n]{0};

		dfs(0,visited);

		return ans;
	}

	void topological_sort_bfs(int src){

		queue<int>q;
		unordered_map<int,int>indeg;

		for(auto it: m){
			for(auto i: it.second){
				indeg[i]++;
			}
		}

		q.push(src);
		// int *visited = new int[n];

		// visited[src] = true;

		while(!q.empty()){
			int node = q.front();
			cout<<node<<" ";
			q.pop();

			for(auto it: m[node]){
				indeg[it]--;
				if(indeg[it] == 0)q.push(it);
			}
		}

		cout<<endl;
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

	g.topological_sort_bfs(1);

}