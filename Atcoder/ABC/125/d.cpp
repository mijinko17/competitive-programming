#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int minus=0;
	long long int ans=0;
	int temp;
	int m=1e+9+1;
	for (int i = 0; i < n; i++) {
		cin>>temp;
		if (temp<0) {
			minus++;
		}
		ans+=abs(temp);
		m=min(m,abs(temp));
	}
	if (minus%2==0) {
		cout<<ans<<endl;
	}else {
		cout<<ans-2*m<<endl;
	}
}
