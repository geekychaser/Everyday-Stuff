#include <iostream>
#include<vector>
using namespace std;

int main() {
    
    vector<int>A{1,2,3,4,5};

    
    int n = A.size();
    int num=0;
    
    for(int i=0;i<n;i++){
        num = num*10+A[i];
    }
    
    num = num+1;
    int a =num;
    int count=0;
    vector<int>v;
     vector<int>res;
    
    while(a){
        a =a/10;
        count++;
    }
    
    for(int i=0;i<count;i++){
        int k = num%10;
        v.push_back(k);
        num=num/10;
    }
    
    for(auto it=v.end()-1;it>v.begin();it++){
        res.push_back(*it);
        }
    
    
     for(int i=0;i<n;i++){
        cout<<res[i];
    }


	return 0;
}
