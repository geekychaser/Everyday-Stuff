#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int ans = 0;
int sol[MAX][MAX] = {0};
bool ld[MAX] = {0},rd[MAX] = {0},col[MAX] = {0};

void solve(int n,int i){
	if(i == n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(sol[i][j] == 1){
					cout<<"{"<<i+1<<"-"<<j+1<<"}"<<" ";
				}
			}
		}
		ans++;
		return;
	}

	for(int j=0;j<n;j++){
		if(!col[j] && !rd[i+j] && !ld[j-i]){
			col[j] = rd[i+j] = ld[j-i] = 1;
			sol[i][j] = 1;
			solve(n,1+i);
			sol[i][j] = 0;
			col[j] = rd[i+j] = ld[j-i] = 0;
		}
	}
}


int32_t main(){
	fastIO
	// start();

	int n;
	cin>>n;

	solve(n,0);
	cout<<ans<<endl;

}