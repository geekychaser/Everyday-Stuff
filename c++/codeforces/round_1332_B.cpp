#include<bits/stdc++.h>

#define int long long
#define fastIO ios_base::sync_with_stdio(fasle);cin.tie(NULL);
#define endl "\n"
#define MAX 1001

using namespace std;

vector<bool>check(MAX,1);
vector<int>least_prime(MAX);

void prime_sieve(){

    for(int i=2;i*i<MAX;i++){
        if(check[i] == true){
            least_prime[i] = i;
            for(int j=i*i;j<MAX;j+=i){
                check[j] = false;
                least_prime[j]=i;
            }
        }
    }

    // for(int i=2;i<MAX;i++){
    //     if(check[i] == true) prime.push_back(i);
    // }


    // for(int i=2;i<MAX;i++){
    //     cout<<least_prime[i]<<" ";
    // }

    // for(auto it : prime)cout<<it<<" ";
}

int32_t main(){

    int t;
    cin>>t;

    prime_sieve();

    while(t--){
        int n;
        cin>>n;

        int a[n];
        vector<int>ans;
        set<int>s;

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        map<int,int>m;
        int count = 1;
        for(int i=0;i<n;i++){
            int temp = least_prime[a[i]];
            // cout<<least_prime[a[i]]<<" ";
            if(m.find(temp) == m.end()){
                m[temp] = count;
                count++;
            }
            ans.push_back(m[temp]);
            s.insert(m[temp]);
        }

        cout<<s.size()<<endl;
        for(auto it: ans)cout<<it<<" ";

        cout<<endl;
    }
}