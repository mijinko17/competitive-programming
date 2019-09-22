#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> b(n);
	int tx,ty;
	for (int i = 0; i < n; i++) {
		cin>>tx>>ty;
		b[i]=make_pair(tx,ty);
	}
	int p,q;
	vector<vector<int>> d;
	int picked=0;
	int flag1=1;
	int flag2;
	while (picked<n) {

	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i; j < n; j++) {
			p=b[i].first-b[j].first;
			q=b[i].second-b[j].second;
		}
	}
}
