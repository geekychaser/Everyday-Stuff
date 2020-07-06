#include<bits/stdc++.h>

#define ll long long
#define endl "\n"

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
	start();
	ll t;
	cin>>t;

	while(t--){
		ll d,c;
		cin>>d>>c;

		ll sol = 0;

		if(d > c){
			sol = c*(c+1)/2;
		}
		else{
			d--;
			sol = d*(d+1)/2;
			sol++;
		}

		cout<<sol<<endl;
	}
}