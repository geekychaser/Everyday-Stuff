#include <iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int>& v){
    int n = v.size();
    
    for(int i=1;i<n;i++){
        int temp = v[i];
        int hole = i;
        
        while(hole>0 && v[hole-1]>temp){
            v[hole] = v[hole-1];
            hole--;
        }
        v[hole] = temp;
    }
}
using namespace std;

int main() {

vector<int>v = {6,5,4,3,2,1};

insertion_sort(v);

for(auto y : v){
    cout<<y<<' ';
    
}
	return 0;
}
