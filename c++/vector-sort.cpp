#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(int k){
	cout<<k<<" ";
}

int main()
{

	int n;
	cin>>n;

	vector<int> v(n);

	for(auto& i : v){
		cin>>i;
	}
	
	sort(v.begin(),v.end());

	for_each(v.begin(),v.end(),print);

return 0;
}
