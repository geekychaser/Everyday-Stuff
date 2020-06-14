#include<bits/stdc++.h>

using namespace std;

int n;

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

	void add_edge(int x,int y){
		m[x].push_back(y);
	}

	bool dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>stack){

		visited[node] = true;
		stack[node] = true;

		for(auto it: m[node]){
			if(stack[it] == true){
				return true;
			}

			else if(visited[it]!= true && dfs(it,visited,stack)){
				return true;
			}
		}

		stack[node] = false;
		return false;
	}

	bool cycle(){
		unordered_map<int,bool>visited;
		unordered_map<int,bool>stack;

		if(dfs(0,visited,stack)) return true;

		for(int i=1;i<n;i++){
			if(!visited[i]){
				if(dfs(i,visited,stack)) return true;
			}
		}

		return false;
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

	if(g.cycle()) cout<<"cycle hai"<<endl;
	else cout<<"cycle nahi hai";


}