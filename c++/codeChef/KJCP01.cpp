#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100001

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

class details{
public:
	int idx;
	int freq = 0;
};

bool comp(details a,details b){
	if(a.freq == b.freq){
		return a.idx < b.idx;
	}

	return a.freq > b.freq;
}

int32_t main(){
	fastIO
	start();

	int n,m;
	cin>>n>>m;

	int a[n];
	vector<details>v(MAX);
	int temp;

	for(int i=0;i<n;i++){
		cin>>temp;
		if(v[temp].freq == 0){
			v[temp].idx = i;
			v[temp].freq = 1;
		}
		else{
			v[temp].freq++;
		}
	}

	sort(v.begin(),v.end(),comp);


	for(int i=0;i<v.size();i++){

		for(int j=0;j<v[i].freq;j++){
			cout<<i<<" ";
		}
	}


}