#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<string>v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        vector<int>freq(26);

        for(int i=0;i<n;i++){
            for(auto ch: v[i]){
                freq[ch - 'a']++;
            }
        }

        bool ans = true;
        for(int i=0;i<26;i++){
            if(freq[i]%n){
                ans = false;
                break;
            }
        }

        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}