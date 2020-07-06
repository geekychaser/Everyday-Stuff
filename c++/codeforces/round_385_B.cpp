#include<bits/stdc++.h>

using namespace std;


#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";

void start(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

}

int32_t main(){
    start();
    
    string s;
    cin>>s;

    vector<int>v;
    int n = s.length();
    // cout<<n<<endl;
    string check = "bear";
    int ans = 0;
    for(int i=0;i<n-3;i++){
        if(s.compare(i,4,check) == 0){
            v.push_back(i+1);
        }
    }

    
    if(v.size() == 0){
        cout<<"0"<<endl;
        return 0;
    }
    ans += (v[0]) * (n - (v[0]+2));

    for(int i=1;i<v.size();i++){
        ans += (v[i] - v[i-1]) * (n - (v[i] + 2));
    }
    
    cout<<ans<<endl;
}