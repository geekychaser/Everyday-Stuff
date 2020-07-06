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
void solve(int *a,int i,int n,int k,vector<int>v){
	if(k == 0){
        for(auto i:v){
        	cout<<i<<" ";
        }
        cout<<" ";
        ans++;
        return;
    }

    if(k < 0 || i >= n){
        return;
    }
    
    
    	v.push_back(a[i]); 
        solve(a,i+1,n,k-a[i],v);
        v.pop_back();
        solve(a,i+1,n,k,v);
        

        
}



int32_t main(){
	fastIO
	start();
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	// sort(a,a+n);
	int target;
	cin>>target;
	// cout<<"target "<<target<<endl;
	vector<int>temp;
	solve(a,0,n,target,temp);

	// for(auto it: ans){
	// 	for(auto i: it){
	// 		cout<<i<<" ";
	// 	}
	// 	cout<<" ";
	// }

	cout<<endl<<ans<<endl;
	


}