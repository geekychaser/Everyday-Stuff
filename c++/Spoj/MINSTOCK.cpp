#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}


int32_t main(){
	fastIO
	start();

	int t;
	cin>>t;
	int test = 0;
	map<string , int>det;
	map<int,string>rem;

	while(t--){
		test++;

		int val,p;
		string name;

		cin>>val;

		if(val == 1){
			cin>>name;
			cin>>p;
			rem[p] = name;
			det[name] = p;
			// cout<<"chla 1 "<<pq.size()<<endl;
		}
		else if(val == 2){
			cin>>name;
			cin>>p;
			int temp = det[name];
			rem.erase(temp);
			det[name] = p;
			rem[p] = name;
			// cout<<"chl 2 "<<pq.size()<<endl;
		}
		else{
			cin>>name;
			// cout<<"chla 3"<<endl;

			cout<<rem.begin()->second<<" "<<test<<endl;
			det.erase(rem.begin()->second);
			rem.erase(rem.begin()->first);
		}
		// pi temp = pq.top();
		// cout<<val<<" "<<temp.first<<" "<<temp.second<<endl;
	}

}