#include<bits/stdc++.h>

#define int long long
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";


using namespace std;

bool comp(pair<int,int>p1,pair<int,int>p2){
    return p1.second < p2.second;
}

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.first > p2.first;
}

int32_t main(){
    fastIO

    int n;
    cin>>n;
    vector<pair<int,int>>v1;
    vector<pair<int,int>>v2;

    map<pair<int,int>,int>m;
    pair<int,int>temp;

    for(int i=0;i<n;i++){
        cin>>temp.first>>temp.second;

        if(temp.first < temp.second) v1.push_back(temp);
        else v2.push_back(temp);

        m[temp] = i+1;
    }

    sort(v1.begin(),v1.end(),compare);
    sort(v2.begin(),v2.end(),comp);

    if(v1.size() > v2.size()){
        cout<<v1.size()<<"\n";
        for(auto it : v1){
            cout<<m[it]<<" ";
            // cout<<it.first<<" "<<it.second;
        }
    }else{
        cout<<v2.size()<<"\n";
        for(auto it : v2){
            cout<<m[it]<<" ";
            // cout<<it.first<<" "<<it.second;
        }
    }

}