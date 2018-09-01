#include<iostream>
#include<string>
using namespace std;

int decode(string s){
    string str ="";
    //cout<<"chla"<<endl;
    int sum=0;
    int n = s.length();

    for(auto i : s){
        sum = sum*26 + (int)(i - 'A' + '1' - '0');
        // cout<<sum<<endl;
    }
    //sum = sum + (n-1)*25;
    
    return sum;
}

// int vdecode(string &s){
//     int res =0;

//     for(char &c : s){
//         res = res*26 + c - 'A' + 1;
//     }
//     return res;
// }

int main(){
    string s ="AAA";
    int k = decode(s);
    cout<<k<<endl;
}