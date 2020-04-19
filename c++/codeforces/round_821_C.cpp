#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define trick -1

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

	int ans = 0;
	string s;
	int checker = 1;

	list<int>l;

	for(int i=0;i<2*n;i++){
		cin>>s;
		int temp;

		if(s == "add"){
			cin>>temp;
			l.push_front(temp);
		}
		else{
			if(checker == l.front() || trick == l.front()){
				if(checker == l.front())
					l.pop_front();
				checker++;
			}
			else{
				// l.sort();
				ans++;
				// l.pop_front();
				l.push_front(trick);
				checker++;
			}
		}
	}

	cout<<ans<<endl;


}