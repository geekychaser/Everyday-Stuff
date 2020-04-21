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

bool solve(string str,int i){
	if(str[i] == '\0') return true;

	if(str[0]!='a') return false;

	if(str[i] == 'a'){
		if(str[i+1] == 'b' && str[i+2] == 'b'){
			return solve(str,i+2);
		}
		else if(str[i+1] =='\0' || str[i+1] == 'a' ){
			return solve(str,i+1);
		}
		else{
			return false;
		}
	}
	else if(str[i] == 'b'){
		if(str[i+1]=='\0' || str[i+1] == 'a'){
			return solve(str,i+1);
		}
		else {
			return false;
		}
	}
	
}



int32_t main(){
	fastIO
	// start();

	string str;
	cin>>str;

	if(solve(str,0))cout<<"true"<<endl;
	else cout<<"false"<<endl;


}