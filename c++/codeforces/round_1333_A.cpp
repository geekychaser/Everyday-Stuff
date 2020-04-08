#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        char a[n][m];
        int b=0,w=0;

        for(int i=0;i<n;i++){
            char k;
            if(i&1) k= 'W';
            else k = 'B';
            for(int j=0;j<m;j++){
                a[i][j] = k;
                if(k == 'B'){
                    b++;
                    k='W';
                } 
                else{
                    w++;
                    k='B';
                }
            }
        }

        if(b == w){
            if(a[n-1][m-1] == 'B'){
                a[n-2][m-1] = 'B';
            }else{
                a[n-1][m-1] = 'B';
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }

    }
}