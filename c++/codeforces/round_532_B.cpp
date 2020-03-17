#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    // int a[m];
    map<int,int>check;
    vector<int>ans;
    int temp;

    for(int i=0;i<m;i++){
        cin>>temp;
        check[temp]++;
        if(check.size() == n){
            ans.push_back(1);
            for(int j=1;j<=n;j++){
                check[j]--;
                if(check[j] == 0){
                    check.erase(j);
                }
            }
        }else{
            ans.push_back(0);
        }
    }

    for(auto it: ans){
        cout<<it;
    }
}