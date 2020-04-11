#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n";

int32_t main(){
    fastIO
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n);
        int two = 0;

        for(int i=0;i<n;i++){
            cin>>v[i];
            v[i] = abs(v[i]);
            if(v[i]%4 == 0){
                two++;
                v[i] = 0;
            }
            else if(v[i]%2 == 0) {
                v[i] = 2;
                two++;
            }
            else v[i] = 1;
        }

        vector<int>ref;

        for(int i=0;i<n;i++){
            if(v[i]%2 == 0) ref.push_back(i);
        }

        // for(auto it: ref)cout<<it<< " ";
        // cout<<endl;
        
        int pos;
        int s,e;
        int remove = 0;
        for(int i=0;i<two;i++){
            if(v[ref[i]] == 2){
                pos = ref[i];
            
                if(i-1 < 0) s = -1;
                else s = ref[i-1];
                if(i+1 >= two) e = n;
                else e = ref[i+1];
                cout<<pos<<" "<<s<<" "<<e<<endl;
                remove += ((pos - s)*(e - pos));
            }
        }
        // cout<<"rem "<<remove<<endl;
        int total = (n*(n+1))/2;
        int ans = total - remove;

        cout<<ans<<endl;
        // cout<<"two "<<two<<endl;
    }
    
}
