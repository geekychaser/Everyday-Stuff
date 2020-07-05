#include<bits/stdc++.h>

#define ll long long
#define endl "/n"

using namespace std;

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		cout<<(n+1)/2<<endl;
	}

}