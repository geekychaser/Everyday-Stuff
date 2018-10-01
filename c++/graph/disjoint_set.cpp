#include<iostream>
#include<vector>
using namespace std;

void make_parent(vector<int> &p,vector<int>& s){
    for(int i=0;i<p.size();i++){
        p[i]=i;
        s[i]=1;
    }
}

int findParent(vector<int>v,int i){
    if(v[i]==i)
        return i;

        return(v,v[i]);
}

bool cycle(int i,int j,vector<int>v){
    if(v[i]==v[j])
    return true;

    return false;
}

void do_union(vector<int>v,int a,int b){
    int ap = findParent(v,a);
    int bp = findParent(v,b);

    if(ap!=bp){
        v[ap]=bp;
    }

}

void weighted_union(vector<int>&v,vector<int>&s,int a,int b){
    int ap = findParent(v,a);
    int bp = findParent(v,b);

    if(!cycle(a,b,v)){

        if(s[ap]<=s[bp]){
            v[ap] = v[bp];
            s[ap]+=s[bp];
        }
        else{
            v[bp]=v[ap];
            s[bp]+=s[ap];
        }

    }
}

int main(){
    int n=10;
   
    vector<int>v(n);
    vector<int>s(n);

    make_parent(v,s);

    weighted_union(v,s,2,1);
    weighted_union(v,s,4,3);
    weighted_union(v,s,8,4);
    weighted_union(v,s,9,3);
    weighted_union(v,s,6,5);

    for(auto y:v){
        cout<<y<<" ";
    }

    if(cycle(2,3,v))
    cout<<"true";
    else
    cout<<"false";
}
