#include<bits/stdc++.h>

using namespace std;

#define int long long

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int32_t main(){

	start();
	
	int t;
	cin>>t;

	while(t--){
		int n = 9;

		char a[n][n];

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				if(a[i][j] == '1') a[i][j] = '2';
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}


	}

}
