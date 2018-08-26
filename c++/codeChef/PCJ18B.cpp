#include<iostream>
using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        long long sum=n*n;
        
        while(n=n-2){
                if(n>0){
                //cout<<n<<" val"<<endl;
                sum = sum + n*n;
                }
                
                else
                break;
            
        }

        cout<<sum<<endl;
    }
}