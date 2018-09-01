#include<iostream>
#include<string>
#include<math.h>
#include<vector>
using namespace std;

string gen_bits(int k){
    string str ;
    while(k){
    bool in = k&1;
    k >>= 1;
    string s= to_string(in);
    str.insert(0,s);
    }
    return str;


}

int get_int(string str){
    int n = str.length()-1;
    int res=0;
    for(int i=0;i<str.length();i++){
        int k = (int)str[i] - '0';
        // cout<<"k "<<k<<endl;
        res = res + k*pow(2,n);
        // cout<<"res "<<res<<endl;
        n--;
        // cout<<"n "<<n<<endl;
    }

    return res;
}

vector<int> decode(string str){
    vector<int>v;
    int idx =0;
     while(idx < str.length()){
         int count = idx;
         while(count < str.length() && str[count]=='0')
         count++;

         int len = count - idx +1;

         v.emplace_back(get_int(str.substr(count,len)));
         idx = count + len;
     }
     return v;

     }
    
    

string encode(vector<int>v){
    int n= v.size();
    string res="";
    string str="";

    for(int i=0;i<n;i++){
        int no_bites = log2 (v[i]);
        str = gen_bits(v[i]);
        str.insert(0,no_bites,'0');
        res+=str;
    }
    

    return res;

}

int main(){
    vector<int>v = {13,3};
    string str = "00100011010";

    vector<int> s;

    // int en = get_int("1101");

    s = decode(str);

    for(auto i :s){
        cout<<i<<" "<<endl;
    }

    //string en = encode(v);

    // string t = gen_bits(13);



    // cout<<en<<endl;
}