#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	priority_queue<int> a;
	int temp;
	for (int i = 0; i < n; i++) {
		cin>>temp;
		a.push(temp);
	}
	while (m>0) {
		temp=a.top();
		a.pop();
		a.push(temp/2);
		m--;
	}
	long long int ans=0;
	while (a.size()>0) {
		ans+=a.top();
		a.pop();
	}
	cout<<ans<<endl;
}
