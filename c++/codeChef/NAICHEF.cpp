#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--){
        long long a,b;
        double c1=0.0,c2=0.0,n;
        cin>>n>>a>>b;

        vector<long long>v(n);

        for(long long i=0;i<n;i++){
            cin>>v[i];
            if(a == v[i]) c1++;

            if(b == v[i]) c2++;
        }

          cout << fixed <<setprecision(10);
         

        double p = (c1/n)*(c2/n);

        cout<<p<<endl;
    }
}