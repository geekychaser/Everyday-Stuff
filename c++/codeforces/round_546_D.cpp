#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MAX 5000001

using namespace std;

vector<int>least_prime(MAX);
vector<bool>checker(MAX,1);


void Prime_sieve(){
    

    for(int i=2;i*i<MAX;i++){
        if(checker[i] == true){
            least_prime[i] = i;
            for(int j=i*i;j<MAX;j+=i){
                checker[j]=false;
                least_prime[j]=i;
            }
        }
    }

    // for(int i=2;i<MAX;i++){
    //     if(checker[i]==true) prime.push_back(i);
    // }
}

vector<int>factors(MAX);

void cal_factors(){
    factors[0] = 0;
    factors[1] = 0;

    for(int i=2;i<MAX;i++){
        if(checker[i]) factors[i]=1;
        else{
            factors[i] = factors[i/least_prime[i]]+1;
        }
    }

    for(int i=1;i<MAX;i++){
        factors[i] = factors[i] + factors[i-1];
    }


}

int32_t main(){
    fastIO

    Prime_sieve();
    cal_factors();
    int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;
        // cout<<factors[a] <<" "<<factors[b]<<endl;
        cout<<factors[a]-factors[b]<<endl;
    }
}