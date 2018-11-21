#include<iostream>
#include<climits>

using namespace std;

int MtarixChainOrder(int arr[], int n){

    int m[n][n] = {0};

    for(int d=1;d<n-1;d++){

        for(int i=1;i<n-d;i++){
            int j = i+d;
           
            m[i][j] = INT_MAX;

            for(int k=i;k<=j-1;k++){
                int q = (m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j]);
                m[i][j] = min(m[i][j],q);
               
            }
            
        }

    }



        return m[1][n-1];
    }


int main(){
    int ar[] = {1,2,3,4};
    int n = 4;

    cout<<"order is "<<MtarixChainOrder(ar,n)<<"\n";

    return 0;
}