#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int temp;
	vector<double> v(n);
	for (int i = 0; i < n; i++) {
		cin>>temp;
		v[i]=1.0*temp;
	}
	sort(v.begin(),v.end());
	double sum=(v[0]+v[1])/2;
	for (int i = 2; i < n; i++) {
		sum+=v[i];
		sum/=2;
	}
	cout<<sum<<endl;
}
