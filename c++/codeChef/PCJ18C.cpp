#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--){
        long long n,a,k;
        cin>>n>>a>>k;

        long long total = (n-2)*180;
        //cout<<total<<endl;

        long long num = a*n*(n-1) + (k-1)*((2*total) - (2*a*n));
        long long denom = n*(n-1);
        //cout<<d<<endl;

        int gcd = __gcd(num,denom);

        cout<<num/gcd<<" "<<denom/gcd<<endl;
    }

    return 0;
}