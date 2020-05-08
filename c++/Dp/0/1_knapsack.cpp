//recurive code hai 0/1 knapsack ka
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;
#define int long long
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define MAX 100001

int dp[MAX][1002];

int knapsack(int wt[],int val[],int capacity,int n){
    if(n == 0 || capacity == 0) return 0;

    if(wt[n-1] <= capacity){
        return max(val[n-1] + knapsack(wt,val,capacity-wt[n-1],n-1) , knapsack(wt,val,capacity,n-1));
    }

    else return knapsack(wt,val,capacity,n-1);
}

int memoization(int wt[],int val[],int capacity,int n){
    if(n == 0 || capacity == 0) return 0;

    if(dp[capacity][n-1] != -1) return dp[capacity][n-1];

    if(wt[n-1] <= capacity){
        dp[capacity][n-1] = max( (val[n-1] + memoization(wt,val,capacity-wt[n-1],n-1) ) , memoization(wt,val,capacity,n-1));
        return dp[capacity][n-1];
    }

    else{
        dp[capacity][n-1] = memoization(wt,val,capacity,n-1);
        return dp[capacity][n-1];
    }
} 

int bottom_up(int wt[],int val[],int capacity,int n){

    for(int i=0;i<n;i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){

            if(wt[i-1] <= j){
                dp[j][i] = max(val[i-1] + dp[j - wt[i-1]][i-1], dp[j][i-1]);
            }
            else{
                dp[j][i] = dp[j][i-1];
            }
        }
    }

    return dp[capacity][n];
}


int32_t main(){

fastIO 
int n,capacity;
cin>>n>>capacity;

int wt[n],val[n];

for(int i=0;i<n;i++){
    cin>>wt[i];
    cin>>val[i];
}
// memset(dp,-1,sizeof(dp));
// cout<<knapsack(wt,val,capacity,n)<<endl;
// cout<<memoization(wt,val,capacity,n)<<endl;
memset(dp,0,sizeof(dp));
cout<<bottom_up(wt,val,capacity,n)<<endl;


}