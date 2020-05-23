#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;

	int a[n];
	int checker = 0;

	for(int i=0;i<n;i++){
		cin>>a[i];
		checker = checker ^ a[i];

	}
	// cout<<"checker "<<checker<<endl;

	int counter = 0;
	while((checker&1) != 1){
		// cout<<"andar checker"<<checker<<endl;
		checker = checker >> 1;
		counter++;
	}
	// cout<<"counter "<<counter<<endl;
	int mask = 1;
	while(counter > 0){
		mask = mask << 1;
		counter--;
	}
	int phela = 0;
	// cout<<"mask "<<mask<<endl;
	for(int i=0;i<n;i++){
		if(mask & a[i]){
			// cout<<"a i is "<<a[i]<<endl;
			phela = phela ^ a[i];
		}
	}
	// cout<<"phela "<<phela<<endl;
	int dusra = phela;

	for(int i=0;i<n;i++){
		// cout<<a[i]<<" ";
		dusra = dusra ^ a[i];
	}
	// cout<<endl;

	cout<<min(phela,dusra)<<" "<<max(phela,dusra)<<endl;
	return 0;
}