#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	//d[i]:a[i]~a[n-1]での最大値
	vector<int> d(n);
	d[n-1]=a[n-1];
	for (int i = n-2; i >= 0; i--) {
		if (a[i]<=d[i+1]) {
			d[i]=d[i+1];
		}else {
			d[i]=a[i];
		}
	}
	vector<int> profit(n);
	for (int i = 0; i < n; i++) {
		profit[i]=d[i]-a[i];
	}
	sort(profit.begin(),profit.end(),greater<int>());		
	int ans=0;
	int e=0;
	while (profit[e]==profit[0]&&e<n) {
		ans++;
		e++;
	}
	cout<<ans<<endl;
}
