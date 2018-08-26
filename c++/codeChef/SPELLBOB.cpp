#include<iostream>
#include<string>
using namespace std;

int main(){
    long long t;
    cin>>t;

    while(t--){
        string s1,s2;

       cin>>s1;
       cin>>s2;
       
       bool flag = false;

          for(int i=0;i<3;i++){

              bool flag1 = false,flag2=false,flag3=false;

              if(s1[i]=='o' || s2[i]=='o'){
                flag1=true;

                if(i==0){
                    if(s1[i+1]=='b' || s2[i+1]=='b')
                    flag2 = true;

                    if(s1[i+2]=='b' || s2[i+2]=='b')
                    flag3 = true;
                }

                else if(i==1){
                    if(s1[i-1]=='b' || s2[i-1]=='b')
                    flag2 = true;

                    if(s1[i+1]=='b' || s2[i+1]=='b')
                    flag3 = true;
                }

                else if(i==2){
                    if(s1[i-1]=='b' || s2[i-1]=='b')
                    flag2 = true;

                    if(s1[i-2]=='b' || s2[i-2]=='b')
                    flag3 = true;
                }

                 if(flag1 && flag2 && flag3){
                    flag = true;
                    break;
                 }
              }

                
          }


        if(flag)
        cout<<"yes"<<endl;

        else
        cout<<"no"<<endl;


    }
}