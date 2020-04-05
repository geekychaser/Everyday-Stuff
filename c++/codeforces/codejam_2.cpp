#include<bits/stdc++.h>

#define int long long
#define endl "\n";
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";


using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
    if(p1.first == p2.first){
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}

int32_t main(){
    int t;
    cin>>t;

    int test = 0;
    while(t--){
        test++;

        int n;
        cin>>n;
        
        char ans[n];
        
        vector<pair<int,int>>v;
        map<pair<int,int>,list<int>>m;
        
        int a,b;
        
        for(int i=0;i<n;i++){
            cin>>a>>b;
            v.push_back(make_pair(a,b));
            m[make_pair(a,b)].push_back(i);
        }
        
        sort(v.begin(),v.end(),compare);

        bool flag = true;
        
        pair<int,int>task1,task2;
        task1.first = -1;
        task2.first = -1;
        
        for(int i=0;i<n;i++){
            
            if(task1.first == -1){
                task1 = v[i];
                ans[m[v[i]].front()] = 'C';
                m[v[i]].pop_front();
            }
            else if(task2.first == -1){
                task2 = v[i];
                ans[m[v[i]].front()] = 'J';
                m[v[i]].pop_front();
            }
            else if(task1.second <= v[i].first){
                task1 = v[i];
                ans[m[v[i]].front()] = 'C';
                m[v[i]].pop_front();
            }
            else if(task2.second <= v[i].first){
                task2 = v[i];
                ans[m[v[i]].front()] = 'J';
                m[v[i]].pop_front();
            }
            else{
                flag = false;
                break;
            }
        }
        

        // for(int i=0;i<n;i++)cout<<ans[i];
        cout<<"Case #"<<test<<": ";
        if(!flag) cout<<"IMPOSSIBLE";
        else{
            for(int i=0;i<n;i++)cout<<ans[i];
        }
        cout<<endl;
    }
}