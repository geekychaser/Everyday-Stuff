#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>

using namespace std;

int StringToInt(string str){
    int sum=0;
    int c=0;

for(int i=0;i<str.length();i++){
    if(isdigit(str[i])){
        int val = str[i] - '0';
       // cout<<"val "<<val<<endl;
        sum = sum*10;
        sum = sum + val;
        //cout<<"sum "<<sum<<endl;
    }
  
}

//cout<<c<<endl;

return sum;
}

string IntToString(int n){
    string str="";
    
    while(n){
        
        char k = n%10 + '0';
        n = n/10;
       // cout<<"k "<<k<<endl;
        str.push_back(k);
        //cout<<"str "<<str<<endl;
    }

    reverse(str.begin(),str.end());

    return str;

}

int main(){
    string str = "123ab";
    int n=123;

  n =   StringToInt(str);
 str =  IntToString(n);
  cout<<n<<endl;
  cout<<str<<endl;
}