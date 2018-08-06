#include <iostream>
using namespace std;

int main() {

int x=3;
int count =0;

while(x){
    
   
    x = (x&(x-1));
    count++;
}

if(count%2==0){
    cout<<"0 parity";
}
else{
    cout<<"1 parity";
}

	return 0;
}
