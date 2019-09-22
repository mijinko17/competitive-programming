#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin>>h[i];
	}
	int temp=0;
	int ans=0;
	for (int i = 0; i < n-1; i++) {
		if (h[i]>=h[i+1]) {
			temp++;
			ans=max(ans,temp);
		}else {
			ans=max(ans,temp);
			temp=0;
		}
	}
	cout<<ans<<endl;
}
