#include<bits/stdc++.h>

// #define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define PI 3.14159265359


using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int b,c;
        cin>>b>>c;

        double s = 0;
        double e = PI/2;
        double ans = 0;

        while(s<=e){
            double mid = (s+e)/2;
            double p = (2*mid+b)*(sin(mid));
            double q = cos(mid)*(mid*mid+b*mid+c);

            if(p-q == 0){
                ans = mid;
                break;
            }

            if(p-q <= 0){
                ans = mid;
                s = mid;
            }else{
                e = mid;
            }
        }

        double val = (ans*ans+b*ans+c)/sin(ans);
        cout<<setprecision(11)<<val<<"\n";
    }
}