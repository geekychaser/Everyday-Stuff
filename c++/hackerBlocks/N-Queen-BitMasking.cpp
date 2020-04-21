#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100
#define DONE (1<<n)-1

int ans = 0;

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}


void NQueen(int col,int ld,int rd,int n){
	// Base Case
	if(col == DONE){
		ans++;
		return;
	}

	// Recursive case
	int RemainingColumns = DONE&(~(col|ld|rd)); // to check how many remaing colmns are left

	while(RemainingColumns>0){
		int pos = RemainingColumns&(-RemainingColumns); // pick right most bit where we can place the queen 
		RemainingColumns -= pos;                        // remove the posing where we paces the queen 
		NQueen(col|pos,(ld|pos)<<1,(rd|pos)>>1,n);		// one left shift to make the left dia gonal block and (||) to make all diagonal block
	}
}

int32_t main(){
	int n;
	cin>>n;

	NQueen(0,0,0,n);
	cout<<ans<<endl;
}
