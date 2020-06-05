#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
template<typename T>
class Graph{
	unordered_map<T,list<pair<T,ll> > > h;
public:
	void addEdge(T u, T v,ll dist){
		h[u].pb({v,dist});
		h[v].pb({u,dist});
	}
 
	ll dfs(ll node,unordered_map<ll,bool>&visited,ll *count,ll &ans){
		visited[node] = true;
		count[node] = 1;
 
		for(auto it: h[node]){
			if(!visited[it.first]){
				count[node] += dfs(it.first,visited,count,ans);
				ans += 2*min(count[it.first],n-count[it.first]) * it.second;
			}
		}
 
		return count[node];
	}
 
	ll holiday(){
		unordered_map<T,bool> visited;
		ll * count = new ll[n];
		
		for(ll i = 0 ; i < n ; i++)
			count[i] = 0;
		ll ans = 0;
		dfs(0,visited,count,ans);
		return ans;
	}
};
 
int main(){
	fastIO
 
	ll t,counter=1;
	cin>>t;
	while(t--){
		Graph<ll> g;
		cin>>n;
		for(ll i = 1 ; i<n ; i++){
			ll x,y,z;
			cin>>x>>y>>z;
			g.addEdge(x-1,y-1,z);
		}
		cout<<"Case #"<<counter<<": "<<g.holiday()<<endl;
		counter++;
	}
 
	return 0;
} 