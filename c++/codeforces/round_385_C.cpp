#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 10000005 //MAX kum kardo agar local pe chalana hai toh

int32_t main(){
    fastIO
    int n;
    cin>>n;

    // map<int,int>m;
    int m[MAX] = {0};
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }

    vector<int>primes(MAX,1);
    vector<int>factors(MAX,0);

    for(int i=2;i<MAX;i++){
        if(primes[i]){
            for(int j=i;j<MAX;j+=i){
                primes[j] = false;
                // if(m.find(j)!=m.end()){
                    factors[i] += m[j];
                // }
            }
            // factors[i] = factors[i] + factors[i-1];
        }
    }

    for(int i=2;i<MAX;i++){
        factors[i] = factors[i] + factors[i-1];
        // cout<<factors[i]<<" ";
    }
    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        if(l > MAX-1) l = MAX-1;
        if(r > MAX-1) r = MAX-1;
        // cout<<factors[r]<<" "<<factors[l-1]<<endl;
        cout<<factors[r] - factors[l-1]<<endl;
    }
}