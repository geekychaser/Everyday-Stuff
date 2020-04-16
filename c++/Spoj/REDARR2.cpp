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

	while(t--){
		int n;
		cin>>n;

		// vector<int>v(n);
		// vector<int>ans;
		int sum = 0;
		int temp;

		priority_queue<int,vector<int>,greater<int> >pq;
		for(int i=0;i<n;i++){
			cin>>temp;
			pq.push(temp);
			// sum += v[i];
		}

		while(pq.size()!=1){
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			pq.push(a+b);
			sum +=  a+b;
		}

		cout<<sum<<endl;

	}


}