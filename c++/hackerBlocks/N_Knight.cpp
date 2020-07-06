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
int X[] = {-2,-1,1,2,2,1,-1,-2};
int Y[] = {1,2,2,1,-1,-2,-2,-1};
set<string>after;

void mark(int a,int b,int n){
	for(int i=0;i<8;i++){
		int pos_x = (a+X[i]);
		int pos_y = (b+Y[i]);
		if(pos_x >= 0 && pos_x <= n && pos_y >=0 && pos_y <= n){
			sol[pos_x][pos_y] = -1;
		}
	}
}

void unmark(int a,int b,int n){
	for(int i=0;i<8;i++){
		int pos_x = (a+X[i]);
		int pos_y = (b+Y[i]);
		if(pos_x >= 0 && pos_x <= n && pos_y >=0 && pos_y <= n){
			sol[pos_x][pos_y] = 0;
		}
	}
}

void solve(int n,int i,int x,int y){
	if(i == n){
		string s = "";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(sol[i][j] == 1){
					s +="{" + to_string(i) + "-" + to_string(j) + "}" + " ";
				}
			}
		}
		after.insert(s);
		ans++;
		return;
	}

	for(int j=x;j<n;j++){
		for(int k=(x == j?y:0);k<n;k++){
			if(!sol[j][k]){
				sol[j][k] = 1;
				mark(j,k,n);
				solve(n,i+1,j,k);
				sol[j][k] = 0;
				unmark(j,k,n);
			}
		}
	}
}


int32_t main(){
	fastIO
	start();

	int n;
	cin>>n;

	solve(n,0,0,0);
	
	for(auto it: after){
		cout<<it<<" ";
	}
	cout<<endl<<after.size()<<endl;

}