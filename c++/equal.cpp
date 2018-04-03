#include<iostream>
#include<vector>

using namespace std;

int main()
{

	int n;
	cin>>n;
	
	vector<int> v(n);
	vector<int> v1(n);

	for(auto& i : v){
		cin>>i;
	}

	for(auto& j: v1){
		cin>>j;
	}

	if(v==v1)
		cout<<"equal h bhai";

	else
		cout<<"equal ni h bhai";
return 0;
}
