#include <iostream>
#include<vector>
using namespace std;


void spiral(vector< vector<int> >v){
    int t,b,l,r,dir;
    
    t=0;
    b=v.size()-1;
    l=0;
    r=v[0].size()-1;
    
    dir =0;
    
    while(t<=b && l<=r){
        
        if(dir == 0){
            for(int i=l; i<=r;i++){
                cout<<v[t][i]<<" ";
            }
            t++;
        }
        
        if(dir == 1){
            for(int i=t;i<=b;i++){
                cout<<v[i][r]<<" ";
            }
            
            r--;
        }
        
        if(dir == 2){
            for(int i=r ; i>=l;i--){
                cout<<v[b][i]<<" ";
            }
            b = b-1;
        }
        
        if(dir == 3){
            for(int i=b;i>=t;i--){
                cout<<v[i][l]<<" ";
            }
            l=l+1;
        }
        
        dir = (dir+1)%4;
    }
}

int main() {

vector< vector<int> > v { {1,2,3,4},
                          {5,6,7,8},
                          {9,10,11,12},
                          {13,14,15,16} };
                          
    spiral(v);
                        
	return 0;
}
