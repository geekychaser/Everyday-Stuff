#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define trick -1

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}


int Max_Xor(int arr[], int n, int k) 
{ 
  
    // Initialize result 
    int maxXor = INT_MIN; 
  
    // Traverse all subsets of the array 
    for (int i = 0; i < (1 << n); i++) { 
  
        // __builtin_popcount() returns the number 
        // of sets bits in an integer 
        if (__builtin_popcount(i) == k) { 
  
            // Initialize current xor as 0 
            int cur_xor = 0; 
            for (int j = 0; j < n; j++) { 
  
                // If jth bit is set in i then include 
                // jth element in the current xor 
                if (i & (1 << j)) 
                    cur_xor = cur_xor ^ arr[j]; 
            } 
  
            // Update maximum xor so far 
            maxXor = max(maxXor, cur_xor); 
        } 
    } 
    return maxXor; 
} 



int32_t main(){
	fastIO
	start();

	int test;
	cin>>test;
	// int t=0;

	while(test--){
		// t++;
		int n,k;
		cin>>n>>k;

		int a[n];

		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		cout<<Max_Xor(a,n,k)<<endl;
	}

	



	


}