#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second == p2.second) 
        return p1.first < p2.first;
        
        return p1.second < p2.second;
        }

int32_t main(){
    int n,r,avg;

    cin>>n>>r>>avg;

    vector<pair<int,int>>v;

    int a,b;
    int sum = 0;

    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        sum += a;
    }

    sort(v.begin(),v.end(),comp);
    int ans = 0;

    if(sum/n >= avg){
        ans = 0;
    }
    else{
        int req = (avg*n) - sum;
        int i = 0;

        while(req!=0){
            if(v[i].first < r){
                int mul = min(req,r-v[i].first);
                ans += mul*v[i].second;
                req-= mul;
                v[i].first+=mul;
                if(v[i].first == r) i++;
            }else{
                i++;
            }
        }
    }
    cout<<ans<<endl;

}