#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int l,r,tl,tr;
	l=0;
	r=n-1;
	for (int i = 0; i < m; i++) {
		cin>>tl>>tr;
		l=max(l,tl-1);
		r=min(r,tr-1);
	}
	cout<<max(0,r-l+1);
}
