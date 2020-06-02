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

template<typename T>
class Graph{
	unordered_map<T,list<T>>mp;

	public:

		// Graph(){
		// 	m.clear();
		// }

		void add_edge(T x,T y, bool bidir = false){
			mp[x].push_back(y);

			
		}

		void bfs(T src,T dest){

			queue<T>q;
			q.push(src);

			map<T,int>val;
			for(auto it: mp){
				val[it.first] = INT_MAX;
			}
			val[src] = 0;

			while(!q.empty()){
				 T temp = q.front();
				 q.pop();

				 for(auto i: mp[temp]){
				 	if(val[i] == INT_MAX){
				 		q.push(i);
				 		val[i] = val[temp] + 1;
				 	}
				 }
			}
            
            // for(auto i: val){
            //     cout<<i.first<<" "<<i.second<<endl;
            // }
			cout<<val[dest]<<endl;
		}
};

int main(){

	start();

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		map<int,int>mark;

		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
            mark[x] = y - x;
// 			if(x < y) mark[x] = y;
// 			else mark[x] = -1*y;
		}

		// for(auto it : mark){
		// 	cout<<it.first<<" "<<it.second<<endl;
		// }
		Graph<int>g;

		for(int i=0;i<=30;i++){
			for(int j=1;j<=6;j++){

				int val = i + j;
				val += mark[val];

				if(val <= 30){
					g.add_edge(i,val);
				}
			}
		}
		g.add_edge(30,30);

		g.bfs(1,30);

		
	}
}