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

class couple{
public:
	int diff;
	int f;
	int s;
};


class comp{
public:
	bool operator ()(couple a,couple b){
		if(a.diff == b.diff){
			return a.f > b.f;
		}

		return a.diff > b.diff;
	}
};

//important point ye hai ki bahut saare pairs chot jayenge agar -1 +1 krke chaleneg toh
// isley lower bound se peeche and upper kyuki agar beech k pair nikal bhi jaaye
// toh uske baad vaal index hi consider ho


int32_t main(){
	fastIO
	start();

	int n;
	cin>>n;

	string str;
	cin>>str;

	int a[n];
	priority_queue<couple,vector<couple>,comp>q;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	couple fake;

	set<int>checker;

	for(int i=0;i<str.size()-1;i++){
		if(str[i]!=str[i+1]){
			fake.diff = abs(a[i] - a[i+1]);
			fake.f = i;
			fake.s = i+1;
			q.push(fake);
		}
		checker.insert(i);
		checker.insert(i+1);
	}

	vector<pair<int,int>>ans;
	// couple temp;

	while(!q.empty()){
		fake = q.top();
		q.pop();
		// cout<<fake.f<<" "<<fake.s<<endl;
		auto del1 = checker.find(fake.f);
		auto del2 = checker.find(fake.s);
		// for(auto it: checker)cout<<it<<" ";
		// 	cout<<endl;
		if(del1 != checker.end() && del2 != checker.end()){

			checker.erase(del1);
			checker.erase(del2);
			ans.push_back({fake.f+1,fake.s+1});
			// cout<<fake.f<<" "<<fake.s<<endl;
			auto ft = checker.lower_bound(fake.f);
			auto st = checker.upper_bound(fake.s);

			if(ft!=checker.end() && st!=checker.end()){
				// cout<<*(--ft)<<" "<<*(st)<<endl;
				int j = *(--ft);
				int k = *(st);
				if(str[j]!=str[k]){
					fake.diff = abs(a[j] - a[k]);
					fake.f = j;
					fake.s = k;
					q.push(fake);
				}
			}
		}

	}

	cout<<ans.size()<<endl;
	for(auto it: ans){
		cout<<it.first<<" "<<it.second<<endl;
	}
	

}