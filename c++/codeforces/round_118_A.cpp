#include<bits/stdc++.h>

using namespace std;


#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";

bool isvowel(char x) 
{ 
    if (x == 'a' || x == 'e' || x == 'i' ||  
        x == 'o' || x == 'u' || x == 'A' ||  
        x == 'E' || x == 'I' || x == 'O' ||
        x == 'U' || x == 'Y' || x == 'y') 
        return true;
    else
        return false; 
} 

int32_t main(){
    string s;
    cin>>s;

    string ans;

    for(int i=0;i<s.length();i++){
        if(!isvowel(s[i])){
            ans.push_back('.');
            ans.push_back(tolower(s[i]));
        }
    }

    cout<<ans<<endl;
}