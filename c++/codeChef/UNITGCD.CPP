#include<bits/stdc++.h>

#define int long long
#define endl "\n"
#define MAX 1000000

using namespace std;

// bool prime[MAX+1]; 

// void Prime_sieve() 
// { 
//     memset(prime, true, sizeof(prime)); 
  
//     for (int p=2; p*p<=MAX; p++) 
//     { 
//         if (prime[p] == true) 
//         {  
//             for (int i=p*p; i<=n; i += p) 
//                 prime[i] = false; 
//         } 
//     } 
// }

int32_t main(){

    // Prime_sieve();

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int sz = n/2;
        
        if(n == 1){
            cout<<"1\n1 1\n";
        }
        else{
            cout<<sz<<endl;
                for(int i=1;i<=n;i+=2){
                    if(i+2 == n){
                        cout<<"3 "<<i<<" "<<i+1<<" "<<i+2<<endl;
                        break;
                    }
                    else{
                        cout<<"2 "<<i<<" "<<i+1<<endl;
                    }
            }    }
        }
    }

        