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

	int n;
	cin>>n;

	int a[n];
	set<int>s;

	for(int i=0;i<n;i++){
		cin>>a[i];

		s.insert(a[i]);
		auto it = s.find(a[i]);

		// it--;
		if(it == s.begin())cout<<"-1"<<endl;
		else {
			it--;
			cout<<*it<<endl;
		}
	}
}