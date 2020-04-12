#include<bits/stdc++.h>

using namespace std;


#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";

int32_t main(){
    int q;
    cin>>q;

    while(q--){
        int n,m;
        cin>>n>>m;

        bool flag = true;

        vector<int>v(n);
        vector<int>lo(n);
        vector<int>hi(n);
        for(int i=0;i<n;i++){
            cin>>v[i]>>lo[i]>>hi[i];
        }

        int pre = 0;
        int mi = m, ma = m;

        for(int i=0;i<n;i++){
            ma += v[i] - pre;
			mi -= v[i] - pre;
			if (ma < lo[i] || mi > hi[i])
			{
				flag = false;
				break;
			}
			ma = min(ma, hi[i]);
			mi = max(mi, lo[i]);
			pre = v[i];
        }

        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}