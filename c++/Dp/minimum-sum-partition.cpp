#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}


// int *v;
// int dp[51][10002];

 // bool solve(int n,int sum){
 //        if(sum == 0) return 1;
 //        if(n == 0 || sum < 0) return 0;
        
 //        if(dp[n][sum] != -1){
 //        	cout<<"n is"<<dp[n][sum]<<endl;
 //        	return dp[n][sum];
 //        } 
 //        bool test;
 //        cout<<"num "<<v[n-1]<<endl;
 //        if(v[n-1] <= sum){
 //             dp[n][sum] = solve(n-1,sum - v[n-1]) || solve(n-1,sum);
 //             cout<<"if mai "<<dp[n][sum]<<endl;
 //             return dp[n][sum];
 //        }
 //        else 
 //        	dp[n][sum] = solve(n-1,sum);
 //        cout<<"else mai "<<dp[n][sum]<<endl;
 //        return dp[n][sum];
 //    }



int32_t main(){
	fastIO
	start();

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		// v = new int[n];
		vector<int>v(n);

		int range = 0;

		for(int i=0;i<n;i++){
			cin>>v[i];
			range += v[i];
		}

		bool dp[n+1][range+1] = {0};

		memset(dp,0,sizeof(dp));

		// cout<<"range us "<<range<<endl;
		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<=range;j++){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		for(int i=0;i<=n;i++){
			dp[i][0] = 1;
		}
		for(int i=1;i<=range;i++){
			dp[0][range] = 0;
		}

		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<=range;j++){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		for(int i=1;i<=n;i++){
			for(int j=1;j<=range;j++){
				if(v[i-1] <= j){
					dp[i][j] = dp[i-1][j] || dp[i-1][j - v[i-1]];
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		// memset(dp,-1,sizeof(dp));
		

		// solve(n,range);

		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<=range;j++){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		int ans = INT_MAX;

		for(int i=0;i<=range;i++){
			// cout<<"i is "<<i<<" "<<dp[n][i]<<endl;
			if(dp[n][i] == 1){
				// cout<<"is is "<<i<<endl;
				ans = min(ans,abs(range - 2*(i)));
			}
		}
		cout<<ans<<endl;
	}

}