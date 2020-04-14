#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int n = 9;
       char a[n][n];

       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               cin>>a[i][j];
           }
       }

    //    for(int i=0;i<n;i++){
    //        for(int j=0;j<n;j++){
    //            cout<<a[i][j];
    //        }
    //         cout<<endl;
    //    }

        int r = 0;
        int col = 0;

       for(int i=0;i<n;i++){
           a[i][i] = a[i][n-1];
           if( i == n-1){
               a[i][i] = a[i][0];
           }
       }

       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               cout<<a[i][j];
           }
            cout<<endl;
       }



    }
}