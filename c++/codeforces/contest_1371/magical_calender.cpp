#include<bits/stdc++.h>

#define ll long long
#define endl "\n"
using namespace std;


int main(){
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