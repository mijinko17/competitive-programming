#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	long long int sum=0;
	int r=0;
	long long int ans=0;
	for (int i = 0; i < n; i++) {
		while (sum<k&&r<n) {
			sum+=a[r];
			r++;
		}
		if (sum>=k) {
			ans+=n-r+1;
		}
		sum-=a[i];
	}
	cout<<ans<<endl;
}
