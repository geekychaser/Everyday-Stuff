#include<iostream>
#include<vector>

using namespace std;

int main()
{

	int n;
	cin>>n;

	vector<int> v(n);
	vector<int>temp(n);
	
	for(auto& i : v){
		cin>>i;
	}

	for(int i=0;i<n;i++){
		temp[i]=v[i];
	}

	int r;
	cin>>r;

	for(int j=0;j<n;j++){
		if(j+r+1>n-1)
			v[j+r+1-n] = temp[j];

		else
			v[j+r+1] = temp[j];

	}

	for(auto i : v){
		cout<<i<<" ";
	}

return 0;

}
