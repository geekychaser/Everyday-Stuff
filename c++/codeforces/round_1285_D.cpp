#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define trick -1

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int solve(vector<int>a,int bit){
	if(a.empty() || bit < 0){
		return 0;
	}

	int mask = (1<<bit);

	vector<int>zero;
	vector<int>one;

	for(int i=0;i<a.size();i++){
		if(a[i]&mask) one.push_back(a[i]);

		else zero.push_back(a[i]);
	}

	if(zero.empty()) return solve(one,bit-1);
	if(one.empty()) return solve(zero,bit-1);

	return min(solve(zero,bit-1),solve(one,bit-1)) + (1<<bit);
}



int32_t main(){
	fastIO
	start();

	int n;
	cin>>n;

	vector<int>a(n);

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<solve(a,30)<<endl;
	



	


}