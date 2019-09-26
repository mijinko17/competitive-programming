#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n;
	cin>>n;
	vector<long long int> t(5);
	for (long long int i = 0; i < 5; i++) {
		cin>>t[i];
	}
	sort(t.begin(),t.end());
	cout<<(n+t[0]-1)/t[0]+4<<endl;
}
