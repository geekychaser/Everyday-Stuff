#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll num;
        cin>>num;

        string s = to_string(num);

        string ans = "";

        for(int i=0;i<n;i++){
            if(s[i] == '0' || s[i] == '1'){
                ans.push_back('0');
            }else{
                ans.push_back('1');
            }
        }

        ll i_val = stoi(ans);
        ll j_val = num - i_val;

        cout<<max(i_val,j_val)<<"\n"<<min(j_val,i_val)<<"\n";
    }
}