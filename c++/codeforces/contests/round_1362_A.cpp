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
	// fastIO
	start();

	int t;
	cin>>t;

	while(t--){
		int a,b;
		cin>>a>>b;

		if(a == b) cout<<"0"<<endl;
		else{
			int ans = 0;
			bool flag = false;
			while(a!=b){

				if(a > b){
					if(b*8 <= a){
						ans++;
						b = b*8;
					}
					else if(b*4 <= a){
						ans++;
						b = b*4;
					}
					else if(b*2 <= a){
						ans++;
						b = b*2;
					}
					else{
						flag = true;
						break;
					}
				}
				else{
					if(b/8 >= a && b%8 == 0){
						b = b/8;
						ans++;
					}
					else if(b/4 >= a && b%4 == 0){
						b = b/4;
						ans++;
					}
					else if(b/2 >= a && b%2 == 0){
						ans++;
						b = b/2;
					}
					else{
						flag = true;
						break;
					}
				}
			}

			if(flag) cout<<"-1"<<endl;
			else cout<<ans<<endl;
		}
	}
}