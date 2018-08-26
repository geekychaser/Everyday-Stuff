#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--){
        long long n , k,m=0;
       

        cin>>n>>k;
         vector<long long>v(n);

        for(long long i=0;i<n;i++){
                cin>>v[i];
        }

        for(long long i=0;i<n-k+1;i++){
            long long sum =0;

            for(int j=i;j<i+k;j++){
                sum = sum + v[j];
                m = max(m,sum);
            }
        }

        cout<<m<<endl;
    }
}