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

	int t;
	cin>>t;
	int cases = 0;
	while(t--){
		cases++;
		int a,b,c;
		cin>>a>>b>>c;

		cout<<"Case "<<cases<<": ";
		if(c % (__gcd(a,b)) == 0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}

	}


}