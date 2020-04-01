#include<bits/stdc++.h>

#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";


using namespace std;

int32_t main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int n = s.length();
        int i = 0;

        string ans = "";
        map<char,bool>m;

        for(int i=0;i<n;i++){
            int j = i;
            while(j!=n-1 && s[i] == s[j+1]){
                j++;
            }
            if((j-i)%2==0){
                m[s[i]] = true;
            }
            i = j;

        }

        for(auto it : m){
            cout<<it.first;
        }
        cout<<"\n";
    }

}