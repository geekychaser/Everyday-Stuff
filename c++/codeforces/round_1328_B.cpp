#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n,k;
        cin>>n>>k;

        string s = "";

        for(int i=0;i<n-2;i++){
            s.push_back('a');
        }

        s.push_back('b');
        s.push_back('b');
        k--;
        while(k--){
            ll i = n-1;
            while(true){
                if(s[i] == 'b' && s[i-1] == 'b' && i != n-1){
                    swap(s[i],s[n-1]);
                    swap(s[i-1],s[i-2]);
                    // cout<<s<<endl;
                    break;
                }else if(s[i] == 'b' && s[i-1] == 'b'){
                    swap(s[i-1],s[i-2]);
                    // cout<<s<<endl;
                    break;
                }else if(s[i] == 'b' && s[i-1] == 'a'){

                    swap(s[i],s[i-1]);
                    break;
                }else{
                    // cout<<s<<" ";
                    // cout<<s[i]<<i<<" ";
                    // cout<<"galti"<<endl;
                    i--;
                }
                // i--;
            }
        }

        cout<<s<<endl;
    }
}

// aaabb
// aabab
// baaba
// bbaaa
// abb
// bab
// aaaaabaaaaabaaaaaaaa
