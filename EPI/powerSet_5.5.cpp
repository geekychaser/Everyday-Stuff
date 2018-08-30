#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void PowerSet(vector<char>v){
    int l = pow(2,v.size());

    for(int i=0;i<l;i++){

        for(int j=0;j<v.size();j++){

            if(i & (1 << j)){
                cout<<v[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    vector<char>v={'a','b','c'};

    PowerSet(v);

    return 0;

}

