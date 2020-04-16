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

	char a[n][n];

	bool flag = true;
	map<char,int>m;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(i == j || i+j == n-1){
				if(a[i][j] != a[0][0]){
					flag = false;
				}
			}
			m[a[i][j]]++;
		}
	}
	// cout<<flag<<" "<<m.size()<<" "<<m[a[0][0]]<<endl;
	if(flag && m.size() == 2 && m[a[0][0]] == 2*n - 1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

}