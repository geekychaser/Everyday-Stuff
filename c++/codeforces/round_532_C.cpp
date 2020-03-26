#include<bits/stdc++.h>
#define PI 3.14159265

using namespace std;

int main(){
    int n,r;

    cin>>n>>r;

    double num = r*sin(PI/n);
    double den = 1 - sin(PI/n);

    cout<<fixed<<setprecision(7)<<num/den;
}