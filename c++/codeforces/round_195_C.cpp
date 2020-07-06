#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s,s1,s2,s3;
    stack <int> a;
    int b,t;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        getline(cin,s);
        for(int j=0;j<s.length();j++)
        {
            if(s[j]=='(' || s[j]==',' || s[j]==')')
            s[j]=' ';
        }
        istringstream scin(s);
        s1="";
        scin>>s1;
        if(s1=="try")
        a.push(i);
        if(s1=="throw")
        {
            //s2="";
            scin>>s2;
            b=i;
        }
        if(s1=="catch")
        {
            if(a.size()>0)
            {
                t=a.top();
            }
             a.pop();
                //s3="";
                scin>>s3;
            if (s2==s3&&t<b)
            {
                 s.erase(0,s.find('"')+1);
                 s.erase(s.find('"'),s.size());
                 cout<<s;
                 return 0;
            }
        }
    }
cout<<"Unhandled Exception";
return 0;
}