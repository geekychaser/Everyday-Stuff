#include<iostream>
#include<string>

using namespace std;

int LCS(string s1,string s2){

    int a = s1.size();
    int b = s2.size();

    int lcs[a+1][b+1] = {0};

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){

            if(s1[i]==s2[j]){
                lcs[i][j] = 1+lcs[i-1][j-1];
            }
            else
            lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
        }
    }

    return lcs[a][b];
}

int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout<<LCS(s1,s2)<<endl;

    return 0;
}