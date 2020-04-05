#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int32_t main(){
    int n,k;
    cin>>n>>k;

    vector<int>v(n);
    int sum = 0;

    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i<k){
            sum += v[i];
        }
    }
    int ans = sum;
    int j = 0;

    for(int i=k;i<n;i++){
        sum -= v[i-k];
        sum += v[i];
        if(ans > sum){
            j = i-k+1;
            ans = sum;
        }
    }

    cout<<j+1<<endl;
}