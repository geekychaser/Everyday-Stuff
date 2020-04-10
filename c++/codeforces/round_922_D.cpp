#include<bits/stdc++.h>

using namespace std;


#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";

bool comp(string a,string b){
    string ab = a+b;
    string ba = b+a;

    int sol_ab = 0;
    int sol_ba = 0;
    int counter = 0;
    for(int i=0;i<ab.length();i++){
        if(ab[i] == 's') counter++;
        if(ab[i] == 'h') sol_ab += counter;
    }

    counter = 0;

    for(int i=0;i<ba.length();i++){
        if(ba[i] == 's') counter++;
        if(ba[i] == 'h') sol_ba += counter;
    }

    return sol_ab > sol_ba;
    
}

int32_t main(){

    int n;
    cin>>n;

    vector<string>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end(),comp);

    string ans = "";

    for(int i=0;i<n;i++){
        ans += v[i];
    }

    int sol = 0;
    int counter = 0;
    // cout<<ans<<endl;
    for(int i=0;i<ans.length();i++){
        if(ans[i] == 's') counter++;
        if(ans[i] == 'h') sol += counter;
    }

    cout<<sol<<endl;



}