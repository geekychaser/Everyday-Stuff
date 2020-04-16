#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void start(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

}

int32_t main(){
	fastIO
	start();

	int n;
	cin>>n;

	int f=0,s=0;
	string last = "";
	vector<int>ff;
	vector<int>ss;
	int temp;

	for(int i=0;i<n;i++){
		cin>>temp;

		if(temp < 0){
			last = "second";
			temp = abs(temp);
			s+= temp;
			ss.push_back(temp);
		}
		else{
			last = "first";
			f+= temp;
			ff.push_back(temp);
		}
	}

	// cout<<fs<<" "<<ss<<endl;
	// cout<<f<<" "<<s<<endl;

	if(f > s){
		cout<<"first"<<endl;
		return 0;
	}
	else if(s > f){
		cout<<"second"<<endl;
		return 0;
	}
	else{
		for(int i=0;i<min(ff.size(),ss.size());i++){
			if(ff[i] > ss[i]){
				cout<<"first";
				return 0;
			}
			else if(ff[i] < ss[i]){
				cout<<"second"<<endl;
				return 0;
			}
		}

			cout<<last<<endl;
	}

}