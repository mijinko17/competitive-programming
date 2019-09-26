#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int flag;
	long long int m=1e+9+7;
	//素数リストを作る
	vector<int> p;
	for (int i = 2; i <=n; i++) {
		flag=0;
		for (int j = 0; j < p.size(); j++) {
			if (i%p[j]==0) {
				flag=1;
				break;
			}
		}
		if (flag==0) {
			p.push_back(i);
		}
	}
	//答えの計算
	long long int ans=1;
	long long int div;
	long long int nump;
	//素数ごとに個数の計算
	for (int i = 0; i < p.size(); i++) {
		div=p[i];
		nump=0;
		while (n/div>0) {
			nump+=n/div;
			div*=p[i];
		}
		ans*=nump+1;
		ans%=m;
	}
	cout<<ans<<endl;
}
