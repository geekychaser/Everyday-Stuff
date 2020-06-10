#include<bits/stdc++.h>

using namespace std;

class Graph{
	map<int,vector<int>>m;

public:

	Graph(){
		m.clear();
	}

	void add_edge(int x,int y,bool bidir = true){
		m[x].push_back(y);
		if(bidir){
			m[y].push_back(x);
		}
	}

	void bfs(int s){

		queue<int>q;

		q.push(s);
		map<int,bool>visited;

		while(!q.empty()){
			int k = q.front();
			q.pop();
			cout<<k<<" ";

			for(auto it:m[k]){
				if(!visited[it]){
					q.push(it);
				}
			}
		}
	}
};

int main(){
	int t;
	cin>>t;

	while(t--){
		int v,e;
		cin>>v>>e;

		Graph g;
		int s = -1;
		while(e--){
			int x,y;
			cin>>x>>y;
			if(s==-1) s = x;

			g.add_edge(x,y);

		}

		g.bfs(s);
	}
}