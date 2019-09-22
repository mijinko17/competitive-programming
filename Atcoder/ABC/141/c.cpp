#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,q;
	cin>>n>>k>>q;
	vector<int> p(n,k-q);
	int temp;
	for (int i = 0; i < q; i++) {
		cin>>temp;
		p[temp-1]++;
	}
	for (int i = 0; i < n; i++) {
		if (p[i]>0) {
			cout<<"Yes"<<endl;
		}else {
			cout<<"No"<<endl;
		}
	}
}
