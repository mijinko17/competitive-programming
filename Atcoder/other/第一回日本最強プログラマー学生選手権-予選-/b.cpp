#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n,k;
	long long int p=1e+9+7;
	cin>>n>>k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	//同数列内の転倒数
	long long int s=0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i]>a[j]) {
				s++;
			}
		}
	}
	s%=p;
	//別数列間の転倒数
	long long int d=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i]>a[j]) {
				d++;
			}
		}
	}
	d%=p;
	long long int ans=0;
	ans+=s*k;
	ans%=p;
	long long int temp;
	temp=k*(k-1)/2;
	temp%=p;
	temp*=d;
	temp%=p;
	ans+=temp;
	ans%=p;
	cout<<ans<<endl;
}
