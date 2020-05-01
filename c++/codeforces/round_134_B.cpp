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

int ans = INT_MAX;

void solve(int a,int b,int k,int steps){
	if(a == 1 && b == 1){
		ans = min(ans,steps);
		return;
	}

	if(a-b >0 )solve(a-b,b,k,steps+1);
	if(b-a > 0)solve(a,b-a,k,steps+1);
}



int32_t main(){
	fastIO
	start();

	int n;
	cin>>n;

	for(int i=1;i<n;i++){
		solve(i,n-i,n,1);
	}
	if(ans == INT_MAX)cout<<"0"<<endl;
	else cout<<ans<<endl;


}