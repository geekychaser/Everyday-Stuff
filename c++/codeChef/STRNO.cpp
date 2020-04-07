#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        int k,x;
        cin>>x>>k;

        int count = 0;

        while(x%2 == 0){
            x = x/2;
            count++;
        }

        for(int i=3;i*i<=x;i+=2){

            while(x%i == 0){

                x = x/i;
                 count+=1;

            }            
        }

        if(x>2)count++;

        cout<<count<<endl;
        if(count >= k)cout<<"1\n";
        else cout<<"0\n";
    }
}