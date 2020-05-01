#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define prime 119

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int cal_hash(string s,int n){
	int hash = 0;

	for(int i=0;i<n;i++){
		hash += s[i]*pow(prime,i);
	}

	return hash;
}

int recal_hash(string s,int hash,int i,int j){
	hash -= s[i];
	hash = hash/prime;
	hash += s[j]*pow(prime,(j-i)-1);

	return hash;
}

bool check_same(string pat,string s,int pi,int pj, int si,int sj){
	if(pj - pi != sj - si) return false;
	
	while(pi <= pj and si <= sj){
		if(pat[pi] != s[si]){
			return false;
		}
		si++;
		pi++;
	}

	return true;
}


int32_t main(){
	fastIO
	start();

	string s;
	cin>>s;

	string pat;
	cin>>pat;

	int pat_hash = cal_hash(pat,pat.length());
	int hash = cal_hash(s,pat.length());

	for(int i=0;i<=s.length()-pat.length();i++){

		if(pat_hash == hash && check_same(pat,s,0,pat.length()-1,i,i+pat.length()-1)){
			cout<<"match at "<<i<<endl;
		}

		if(i < s.length() - pat.length())
			hash = recal_hash(s,hash,i,i+pat.length());
	}
}