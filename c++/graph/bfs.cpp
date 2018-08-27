#include<iostream>
#include<list>
#include<queue>

using namespace std;

struct graph{
    bool visited = false;
    list<int>l;
    int val =0; 
};

void assign(graph a[],int u,int val){
    a[u].val = val;
}

void add(graph a[],int u,int v){
    a[u].l.push_back(v);
}

void bfs(graph a[]){
    queue<int>q;

    q.push(0);
    a[0].visited = true;

    while(!q.empty()){
        int k = q.front();
        q.pop();

        cout<<a[k].val<<" ";

        for(auto i : a[k].l){
            if(!a[i].visited){
                q.push(i);
                a[i].visited = true;
            }
        }
    }
}

int main(){

    graph a[4];

    assign(a,0,50);
    assign(a,1,60);
    assign(a,2,70);
    assign(a,3,80);

    add(a,0,1);
    add(a,1,2);
    add(a,1,3);
    add(a,2,3);

    bfs(a);

    return 0;
}