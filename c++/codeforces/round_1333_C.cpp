#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

// int findSubarraySum(int arr[], int n, int sum) 
// { 
    
//     unordered_map<int, int> prevSum; 
  
//     int res = 0; 
  
//     int currsum = 0; 
  
//     for (int i = 0; i < n; i++) { 
  
//         currsum += arr[i]; 
  
         
//         if (currsum != 0)  
//             res++;         
  
     
//         if (prevSum.find(currsum - sum) !=  
//                                   prevSum.end())  
//             res += (prevSum[currsum - sum]); 
          
   
//         prevSum[currsum]++; 
//     } 
  
//     return res; 
// } 

int32_t main(){
    int n;
    cin>>n;

    int a[n];
    int ans = 0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        // if(a[i]!=0) ans++;
    }
    int sum = 0;
    int i =0,j=0;
    while(j<=n-1){
        sum += a[j];
        if(sum!=0){
            j++;
        }else{
            ans += ((j-i+1)*(j-i+2))/2;
            cout<<ans<<endl;
            i = j-1;
            j--;
        }
    }
    // for(int i=0;i<n;i++){
    //     if(a[i]!=0){
    //         sum = a[i];
    //         ans++;
    //     }
    //     int count =0;
    //     for(int j=i+1;j<n;j++){
    //         sum += a[j];
    //         if(sum == 0){
    //             break;
    //         }else{
    //             count++;
    //         }
    //     }
    //     ans += count;
    // }
    cout<<ans<<endl;
}