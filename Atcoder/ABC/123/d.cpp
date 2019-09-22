#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z,k;
	cin>>x>>y>>z>>k;
	vector<int> a(x);
	vector<int> b(y);
	vector<int> c(z);
	for (int i = 0; i < x; i++) {
		cin>>a[i];
	}
	for (int i = 0; i < y; i++) {
		cin>>b[i];
	}
	for (int i = 0; i < z; i++) {
		cin>>c[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	vector<vector<vector<int>>> added(x,vector<vector<int>>(y,vector<int>(z)));
	priority_queue<int> q;
}
