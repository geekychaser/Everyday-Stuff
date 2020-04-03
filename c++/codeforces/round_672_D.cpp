#include<bits/stdc++.h>

#define int long long
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ip(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define op(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";

bool check_min(int a[],int n,int k,int mid){

    int sum = 0;
    int grt = 0;
    for(int i=0;i<n;i++){
        if(mid - a[i] > 0){
            sum += mid - a[i];
        }else{
            grt += a[i] - mid;
        }
    }

    if(sum <= k && sum <= grt){
        return true;
    }

    return false;
}

bool check_max(int a[],int n,int k,int mid){

    int sum = 0;
    int sm = 0;
    for(int i=0;i<n;i++){
        if(a[i] - mid > 0 ){
            sum += a[i] - mid;
        }
        else{
            sm += mid - a[i];
        }
    }

    if(sum <= k && sum <= sm){
        return true;
    }

    return false;
}


using namespace std;

int32_t main(){
    int n,k;
    cin>>n>>k;

    int *a = new int[n];

    ip(a,n);
    sort(a,a+n);

    int s = a[0];
    int e = a[n-1];
    int ans_min = a[0];

    while(s <= e){
        int mid = (s+e)/2;

        if(check_min(a,n,k,mid)){
            ans_min = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }

    int ans_max = a[n-1];
    s = a[0];
    e = a[n-1];

    while(s <= e){
        int mid = (s+e)/2;
        if(check_max(a,n,k,mid)){
            ans_max = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }

    }

    cout<<ans_max-ans_min<<"\n";
}