#include<bits/stdc++.h>

#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define endl "\n"

using namespace std;

bool all_passed(int n,int a[],map<int,int>m,int k){

    int days = 0;

    for(int i=k;i>=0;i--){
        
        if(m.find(a[i])!=m.end() && a[i]){
            days += m[a[i]];
            m.erase(a[i]);
        }else{
            if(days > 0){
                days--;
            }
        }
    }

        if(!m.empty() || days >0){
            return false;
            }
    
    // cout<<"d "<<days<<" "<<m.empty()<<endl;
    return true;
}

int32_t main(){
    int n,m;
    cin>>n>>m;

    int a[n];

    ip(a,n);
    map<int,int>b;
    int temp;

    for(int i=0;i<m;i++){
        cin>>temp;
        b[i+1] = temp;
    }

    int s = 0;
    int e = n;

    int ans = -1;

    while(s <= e){
        int mid = (s+e)/2;
        // cout<<mid<<endl;
        bool check = all_passed(n,a,b,mid);
        // cout<<mid<<" "<<check<<endl;
        if(check){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    if(ans == -1)cout<<"-1\n";
    else cout<<ans+1<<endl;

    return 0;
}