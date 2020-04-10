#include<bits/stdc++.h>

using namespace std;


#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define MAX 100005

bool comp(int a, int b){
    return a>b;
}

int32_t main(){
    int n;
    cin>>n;

    int a[MAX] = {0},b[MAX] = {0};

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    sort(a,a+n,comp);
    sort(b,b+n,comp);

    int sum_1 = 0;
    int sum_2 = 0;

    int i=0;
    int j=0;
    bool flag = true;
    int count = 0;

    while(count < (2*n)){

        if(flag){
            if(a[i] >= b[j]){
                sum_1 += a[i];
                i++;
            }else j++;
        }
        else{
            if(b[j] >= a[i]){
                sum_2 += b[j];
                j++;
            }else i++;
        }

        flag =!flag;
        count++;
       
    }

    cout<<sum_1 - sum_2<<endl;
}