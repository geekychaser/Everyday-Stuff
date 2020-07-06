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
	unordered_map<int,list<int>>copy;
	vector<int>order;
	vector<int>comp;
public:
	void add_edge(int x,int y){
		m[x].push_back(y);
		copy[y].push_back(x);
	}

	void dfs(int node,bool *visited){
		visited[node] = true;

		for(auto it:m[node]){
			if(!visited[it]){
				dfs(it,visited);
			}
		}

		order.push_back(node);
	}

	void rev_dfs(int node,bool * visited,int col){
		visited[node] = true;
		comp[node] = col;

		for(auto it:copy[node]){
			if(!visited[it]){
				rev_dfs(it,visited,col);
			}
		}
	}

	int kosaraju(){

		comp.resize(n+1);

		bool *visited = new bool[n]{0};

		for(int i=0;i<n;i++){
			if(!visited[i])
				dfs(i,visited);
		}

		// for(int i=0;i<n;i++){
		// 	cout<<order[i]<<" ";
		// }

		memset(visited,0,sizeof(visited));

		int col = 0;

		for(int i=n-1;i>=0;i--){
			if(!visited[order[i]]){
				// cout<<"ek bari "<<col<<endl;
				col++;
				rev_dfs(order[i],visited,col);
				
			}
		}

		// for(int i=0;i<n;i++){
		// 	cout<<comp[i]<<"--> "<<i<<endl;
		// }

		return col;
		

	}

};

int main(){

	start();

	int t;
	cin>>t;

	while(t--){
		int m;
		cin>>n>>m;

		Graph g;

		while(m--){
			int x,y;
			cin>>x>>y;

			g.add_edge(x,y);
		}

		cout<<g.kosaraju()<<endl;
	}


}