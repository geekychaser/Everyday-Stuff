#include <bits/stdc++.h>

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ip(a, n)                \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define op(a, n)                \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";

using namespace std;

// bool checker()

int32_t main()
{

    IOS

        int n,
        q;
    cin >> n >> q;

    vector<int> v(n);
    int sum = 0;


    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] += sum;
        sum = v[i];
    }

    vector<int> revive = v;
    vector<int>a(q);

    sum = 0;
    for (int i = 0; i < q; i++)
    {
        cin>>a[i];
        a[i] = a[i]+sum;
        sum = a[i];
        if(a[i] >= v[n-1]){
            sum = 0;
        }
    }

    int j = 0;

    for(int i=0;i<q;i++){
        
        j = upper_bound(v.begin(),v.end(),a[i]) - v.begin();
            // if(j == n){
            //     v = revive;
            //     j = 0;
            //     break;
            // }
            // cout<<j<<" ";
            if(j == n)cout<<j<<"\n";
            else cout<<n-j<<"\n";
        }
        
    }
