#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 2001
#define mod 1000000007

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}


int dp[2005][2005][2][2][2];
int m,d;
string l,r;
string s;
// this one is digit dp solution 
int solve(int pos,int mo,int even,int tight,int start){

	if(pos == s.size()){
		if(mo == 0) return 1;
	}

	if(dp[pos][mo][even][tight][start] != -1) return dp[pos][mo][even][tight][start];

	int ans = 0;
	int end = (tight)?s[pos] - '0':9;
	if(start == 0){
		ans = (ans + solve(pos+1,mo,0,tight&(s[pos] == '0'),start)) %mod;
		for(int i=1;i<=end;i++){
			if(i!=d)
			ans = (ans + solve(pos+1,(mo*10+i)%m,1,tight&(i == end),1))%mod;
		}
	}
	else{

		for(int i=0;i<=end;i++){
			if(even && i == d){
				ans = (ans + solve(pos+1,(mo*10+i)%m,!even,tight&(i == end),1))%mod;
			}
			else if(!even && i!=d){
				ans = (ans + solve(pos+1,(mo*10+i)%m,!even,tight&(i == end),1))%mod;
			}
		}
	}

	return dp[pos][mo][even][tight][start] = ans;

}



int32_t main(){
	// fastIO
	start();
	
	
	cin>>m>>d;

	cin>>l>>r;

	memset(dp,-1,sizeof(dp));
	s = r;
	int ans = solve(0,0,0,1,0)%mod;

	memset(dp,-1,sizeof(dp));
	s = l;
	ans = (ans - solve(0,0,0,1,0) + mod)%mod;

	bool flag = true;
	int mo = 0;

	for(int i=0;i<l.size();i++){
		if(i%2 == 0 && l[i] - '0' !=d){
			flag = false;
			break;
		}
		else if(i%2!=0 && l[i] - '0' == d){
			flag = false;
			break;
		}

		mo = (mo*10 + i)%m;
	}

	if(flag && mo == 0){
		ans = (ans+1+mod)%mod;
	}

	cout<<ans<<endl;





}if (/* condition */)
{
	/* code */
}