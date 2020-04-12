#include<bits/stdc++.h>

using namespace std;


#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";

int32_t main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;


    for(int i=0;i<s1.length();i++){
        if(isupper(s1[i])) s1[i]  = tolower(s1[i]);

        if(isupper(s2[i])) s2[i] = tolower(s2[i]);
    }

    if(s1 > s2)cout<<"1"<<endl;
    else if(s1 < s2)cout<<"-1"<<endl;
    else cout<<"0"<<endl;
}