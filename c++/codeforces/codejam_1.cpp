#include<bits/stdc++.h>

#define int long long
#define endl "\n";
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";


using namespace std;

int32_t main(){
    int t;
    cin>>t;

    int test = 0;
    while(t--){
        test++;

        int n;
        cin>>n;

        int a[n][n];

        int tr = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];

                if(i == j) tr+=a[i][j];
            }
        }

        int r = 0;

        for(int i=0;i<n;i++){
            map<int,bool>m;
            for(int j=0;j<n;j++){
                if(m[a[i][j]]){
                    r++;
                    break;
                }
                m[a[i][j]] = 1;
            }
        }

        int c =0;

        for(int i=0;i<n;i++){
            map<int,bool>m;
            for(int j=0;j<n;j++){
                if(m[a[j][i]]){
                    c++;
                    break;
                }
                m[a[j][i]] = 1;
            }
        }

        cout<<"Case #"<<test<<": "<<tr<<" "<<r<<" "<<c<<endl;
    }
}