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


int32_t main(){

fastIO 
int n,capacity;
cin>>n>>capacity;

int wt[n],val[n];

for(int i=0;i<n;i++){
    cin>>wt[i];
    cin>>val[i];
}
memset(dp,-1,sizeof(dp));
// cout<<knapsack(wt,val,capacity,n)<<endl;
cout<<memoization(wt,val,capacity,n)<<endl;


}