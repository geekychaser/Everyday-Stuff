#include<iostream>
#include<list>
using namespace std;

struct graph{
    int val=0;
    bool visited = false;
    list<int>l;

};

void assign(graph g[],int v,int val){
    g[v].val = val;
}

void add(graph g[],int v,int u){
    g[v].l.push_back(u);
}

graph dfs(graph g[],int n){
    
    g[n].visited = true;
    cout<<g[n].val<<" ";

    for(auto i : g[n].l){
        if(!g[i].visited){
            dfs(g,i);
        }
    }
}

int main(){
    graph a[4];

    assign(a,0,0);
	assign(a,1,1);
	assign(a,2,2);
	assign(a,3,3);

	add(a,0,1);
	add(a,1,2);
	add(a,1,3);
	add(a,2,3);

	for(int i=0;i<4;i++){
		if(!a[i].visited)
			dfs(a, i);
	}

	return 0;

}