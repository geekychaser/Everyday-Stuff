#include<bits/stdc++.h>

using namespace std;
#define int long long
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";

bool comp(char a,char b){
    int temp1 = a - '0';
    int temp2 = b - '0';

    if(temp1 < temp2 && (temp2 - temp1 == 1 || temp2 - temp1 == 0)){
        return true;
    }

    return false;
}

int32_t main(){

fastIO 

    string s;
    cin>>s;

    // sort(s.begin(),s.end(),comp);

    string ans = "";
    int ones = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '1')ones++;
        else ans+= s[i];
    }

    int i=0;
    while(i < ans.length() && ans[i] == '0') i++;

    // for(int j=i;j<ones;j++){
    //     ans.insert(i,'1');
    // }

    ans.insert(i,ones,'1');
    cout<<ans<<endl;

}