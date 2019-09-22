#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	vector<pair<int,int>> bc(m);
	int tb,tc;
	for (int i = 0; i < m; i++) {
		cin>>tb>>tc;
		bc[i]=make_pair(tb,tc);
	}
	sort(a.begin(),a.end());
	sort(
		bc.begin(),
		bc.end(),
		[](const pair<int,int>& x,const pair<int,int>& y){return x.second>y.second;}
	);
	int now=0;
	for (int i = 0; i < m; i++) {
		while (bc[i].first>0&&bc[i].second>a[now]) {
			a[now]=bc[i].second;
			now++;
			bc[i].first--;
		}
		if (bc[i].first!=0) {
			break;
		}
	}
	long long int ans=0;
	for (int i = 0; i < n; i++) {
		ans+=a[i];
	}
	cout<<ans<<endl;
}
