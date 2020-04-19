#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 11

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}


bool solve(char a[MAX][MAX],int sol[MAX][MAX],int i,int j,int n,int m){
	if(i == n && j == m){
		sol[i][j] = 1;

		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}

		return true;
	}

	if(i <0 || j<0 || j > m || i > n){
		return false;
	}

	if(a[i][j] == 'X'){
		return false;
	}

	sol[i][j] = 1;
	bool left,up,down,right;

	if(sol[i+1][j] == 0){
		down = solve(a,sol,i+1,j,n,m);
	}

	if(sol[i][j+1] == 0){
		right = solve(a,sol,i,j+1,n,m);
	}

	if(sol[i][j-1] == 0){
		left = solve(a,sol,i,j-1,n,m);
	}

	if(sol[i-1][j] == 0){
		up = solve(a,sol,i-1,j,n,m);
	}

	if(right || left || up || down) return true;

	sol[i][j] = 0;
	return false;
}


int32_t main(){
	fastIO
	// start();

	int n,m;
	cin>>n>>m;

	char a[MAX][MAX];
	int sol[MAX][MAX] = {0};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			sol[i][j] = 0;
		}
	}

	if(!solve(a,sol,0,0,n-1,m-1)){
		cout<<"NO PATH FOUND"<<endl;
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<sol[i][j];
	// 	}
	// 	cout<<endl;
	// }

}