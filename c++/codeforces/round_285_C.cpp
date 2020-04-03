#include<bits/stdc++.h>

#define int long long

using namespace std;

int32_t main(){
    int n;
    cin>>n;

    int a[n+1];

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    int sum = 0;

    for(int i=1;i<=n;i++){
        // cout<<a[i]<<" "<<i<<endl;
        sum += abs(a[i] - i);
        // cout<<sum<<endl;
    }

    cout<<sum<<endl;
}