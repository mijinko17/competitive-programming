#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int max_index=0;
	for (int i = 1; i < n; i++) {
		if (abs(a[i])>abs(a[max_index])) {
			max_index=i;
		}
	}
	cout<<2*n-1<<endl;
	for (int i = 0; i < n; i++) {
		cout<<max_index+1<<" "<<i+1<<endl;
	}
	if (a[max_index]>=0) {
		for (int i = 0; i < n-1; i++) {
			cout<<i+1<<" "<<i+2<<endl;
		}
	}else {
		for (int i = n; i > 1; i--) {
			cout<<i<<" "<<i-1<<endl;
		}
	}
}
