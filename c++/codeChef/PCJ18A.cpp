#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--){
        long long n,x,m=0;
        cin>>n>>x;

        vector<long long>v(n);

        for(long long i=0;i<n;i++){
            int k;
            cin>>k;
            v[i] = k;
            m = max(m,v[i]);
        }

        if(m>=x){
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
}