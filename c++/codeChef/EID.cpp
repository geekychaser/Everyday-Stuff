#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;
        vector<long long>v(n);
        long long ans = INT_MAX;
        for(long long i=0;i<n;i++){
            long long k;
            cin>>k;
            v[i] = k;
            // if(i>0)
            // ans = min(ans,abs(v[i]-v[i-1]));
            
        }

        sort(v.begin(),v.end());

        for(long long i=0;i<n;i++){
            if(i>0)
            ans = min(ans,abs(v[i]-v[i-1]));
        }

        cout<<ans<<endl;


    }
}