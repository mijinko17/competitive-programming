#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int x,y;
	int cand;
	int ans=1e+9;
	for (int i = 0; i <=n; i++) {
		cand=0;
		x=i;
		y=n-i;
		while (x>0) {
			cand+=x%6;
			x/=6;
		}
		while (y>0) {
			cand+=y%9;
			y/=9;
		}
		ans=min(ans,cand);
	}
	cout<<ans<<endl;
}
