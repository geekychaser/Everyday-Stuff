#include<bits/stdc++.h>

using namespace std;

class Graph{
	unordered_map<int,vector<int> >m;

public:

	Graph(){

	}

	void add_edge(int x,int y, bool bidir = true){
		m[x].push_back(y);
		if(bidir){
			m[y].push_back(x);
		}
	}

	void print(int v){

		for(int it=0;it<v;it++){
			cout<<it;
			for(auto i: m[it]){
				cout<<"-> "<<i;
			}
			cout<<endl;
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
		while(e--){
			int x,y;
			cin>>x>>y;

			g.add_edge(x,y);

		}

		g.print(v);
	}
}