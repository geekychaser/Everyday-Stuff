#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edege{
    int start;
    int dest;
    int weight;
};

int findParent(int v,vector<int>p){
    if(p[v]==v)
    return v;

    return findParent(p[v],p);
}

bool compare(edege a, edege b){
    return a.weight < b.weight;
}

void kruskal(edege* k,int e,int n){
    sort(k,k+e,compare);

    edege* res = new edege[n-1];

    int count=0;
    int i=0;

    vector<int>p(n);

    for(int i=0;i<n;i++){
        p[i]=i;
    }

    while(count!=n-1){
        edege curr = k[i];

        int sp = findParent(curr.start,p);
        int dp = findParent(curr.dest,p);

        if(sp!=dp){
            res[count] = curr;
            count++;
            p[sp]=dp;
        }
        i++;



    }

    for(int i=0;i<n-1;i++){
        cout<<res[i].start<<" "<<res[i].dest<<" "<<res[i].weight<<endl;
    }
}

int main(){
    int e , n;
    cin>>n>>e;
    edege* k = new edege[e];

    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;

        k[i].start = s;
        k[i].dest = d;
        k[i].weight = w;
    }

    kruskal(k,e,n);

    return 0;
}