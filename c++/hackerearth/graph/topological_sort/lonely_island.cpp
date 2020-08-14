#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

class Graph{
    unordered_map<int,list<int>>m;

    public:

    void add_edge(int u,int v){
        m[u].push_back(v);
    }

    void dfs(map<int,bool>&visited,int node,vector<int>&arr){

        visited[node] = true;

        for(auto it:m[node]){
            if(!visited[it]){
                dfs(visited,it,arr);
            }
        }

        arr.push_back(node);
    }

    void lonely_island(int src){

        vector<int>arr;
        map<int,bool>visited;
        map<int,int>indeg;

        dfs(visited,src,arr);

        // if src is point where is stuck
        if(arr.size() == 0){
            cout<<"size 0"<<endl;
            cout<<src<<endl;
            return;
        }

        bool check = false;
        for(auto it:m){
            if(check == false){
                if(it.first == src){
                    check = true;
                }
            }
            if(check){
                for(auto i:it.second){
                    indeg[i]++;
                }
            }
        }

        vector<int>ans;
        // cout<<"indeg "<<indeg[97966]<<" "<<m[97966].size()<<endl;
        // cout<<"indeg "<<indeg[110592]<<" "<<m[110592].size()<<endl;
        // cout<<"last ele";
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        ans.push_back(arr[0]);

        for(auto it:arr){
            if(ans[0]!=it && m[it].size() == 0 && indeg[it] >= indeg[ans[0]]){
                if(indeg[it] > indeg[ans[0]]){
                    ans[0] = it;
                }
                else 
                    ans.push_back(it);
            }
        }
        
        for(auto it:ans){
            cout<<it<<" "<<indeg[it]<<" "<<m[it].size()<<endl;
        }
        cout<<endl;
        
    }
};


int32_t main(){
    int n,m,r;

    cin>>n>>m>>r;

    Graph g;

    while(m--){
        int u,v;
        cin>>u>>v;

        g.add_edge(u,v);
    }

    g.lonely_island(r);
}