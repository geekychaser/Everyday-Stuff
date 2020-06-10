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
public:
	void add_edge(int x,int y){
		m[x].push_back(y);
		m[y].push_back(x);
	}

	int bfs(int src){

		queue<int>q;
		q.push(src);

		int cycle_length = INT_MAX;

		vector<int>dist(n+1,INT_MAX);
		dist[src] = 0;

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto it: m[node]){
				if(dist[it] == INT_MAX){
					q.push(it);
					dist[it] = dist[node] + 1;
				}
				else if(dist[it] >= dist[node]){
					cycle_length = min(cycle_length,1 + dist[it] + dist[node]); 
				}
			}
		}

		return cycle_length;
	}

	int shortest_cycle(){

		int ans = INT_MAX;

		for(int i=1;i<=n;i++){
			ans = min(ans,bfs(i));
		}

		return ans;
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

	cout<<g.shortest_cycle()<<endl;
}