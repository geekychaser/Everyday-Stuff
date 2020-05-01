#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define trick -1
#define n 9
void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

bool can_place(int a[n][n],int i,int j,int key){

	for(int k=0;k<n;k++){
		if(a[i][k] == key) return false;
		if(a[k][j] == key) return false;
	}

	int x = (i/3);
	int y = (j/3);
	x = x*3;
	y = y*3;

	for(int e=x;e<x+3;e++){
		for(int f=y;f<y+3;f++){
			if(a[e][f] == key) return false;
		}
	}
	return true;
}

bool solve(int a[n][n],int i,int j){
	if(i == n){
		for(int e=0;e<n;e++){
			for(int f=0;f<n;f++){
				cout<<a[e][f];
			}
		cout<<endl;
	}
		return true;
	}


	if(j == n) return solve(a,i+1,0);

	if(a[i][j] != 0) return solve(a,i,j+1);


	for(int k=1;k<=n;k++){
		if(can_place(a,i,j,k)){
			a[i][j] = k;
			bool sahi_hai_ya_nhi = solve(a,i,j+1);
			if(sahi_hai_ya_nhi) return true;
			a[i][j] = 0;
		}
	}

	return false;
}



int32_t main(){
	fastIO
	// start();
	int temp;
	cin>>temp;
	int a[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}

	if(!solve(a,0,0)) cout<<"nhi chla"<<endl;
}