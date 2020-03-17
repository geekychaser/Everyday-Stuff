#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int a[n];
    int e = 0;
    int s = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i] == -1){
            s++;
        }else{
            e++;
        }
    }

    int sum = 0;
    int ans = 0;
    // cout<<"e "<<e<<"s "<<s<<"\n";
    for(int i=1;i<=k;i++){
            int temp1 = s;
            int temp2 = e;
        for(int j=i;j<=n;j+=k){
            // cout<<"chla ";
            if(a[j] == -1) temp1--;
            else temp2--;
        }
        // cout<<temp1<<temp2<<endl;
        ans = max(ans,abs(temp1-temp2));
    }

    cout<<ans<<'\n';
}