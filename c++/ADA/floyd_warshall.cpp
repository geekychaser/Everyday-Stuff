#include<iostream>
using namespace std;

int floyd_warshall(int m[][4]){

    for(int k=0;k<4;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                m[i][j] = min(m[i][j],m[i][k]+m[k][j]);
            }
        }

    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int k=100;
    int m[4][4] = {{0, 3, k, 7},{8, 0, 2, k},{5, k, 0, 1},{2, k, k, 0}};
    floyd_warshall(m);
}