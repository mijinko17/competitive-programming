#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	string ds=s+s;
	vector<vector<int>> abc(26);
	for (int i = 0; i < ds.length(); i++) {
		abc[ds[i]-'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++) {
		sort(abc[i].begin(),abc[i].end());
	}
	//now:今のsでの添字
	int now=-1;
	long long int ans=0;
	for (int i = 0; i < t.length(); i++) {
		vector<int>& temp=abc[t[i]-'a'];
		auto itr=lower_bound(temp.begin(),temp.end(),now+1);
		if (itr!=temp.end()) {
			ans+=*itr-now;
			now=*itr%s.length();
		}else {
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
}
