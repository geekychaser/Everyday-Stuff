#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];

	}

	int ans[64] = {0};

	for(int j=63;j>=0;j--){
		int temp = 0;
		for(int i=0;i<n;i++){
			if(a[i] & 1) temp++;
			a[i] = a[i] >> 1;
		}
		ans[j] = temp%3;

	}

	int solve = 0;
	int p = 1;

	for(int i=63;i>=0;i--){
		solve += ans[i]*p;
		p = p<<1;
	}
	cout<<solve<<endl;


	return 0;
}