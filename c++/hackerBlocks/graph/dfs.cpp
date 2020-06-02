#include<bits/stdc++.h>

using namespace std;

class Graph{
	unordered_map<int,list<int>>m;

		void dfs_helper(int src,map<int,bool>&visited){

		cout<<src<<" ";
		visited[src] = true;

		for(auto it: m[src]){
			if(!visited[it]){
				dfs_helper(it,visited);
			}
		}
	}


public:

	void add_edge(int x,int y){
		m.push_back(y);
	}


	void dfs(int src){
		map<int,bool>visited;

		dfs_helper(src,visited);
	}
};
int main(){
	
}