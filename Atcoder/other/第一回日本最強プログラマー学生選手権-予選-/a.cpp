#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,d;
	cin>>m>>d;
	int s,t;
	int ans=0;
	for (int i = 1; i <=m; i++) {
		for (int j = 1; j <=d; j++) {
			s=j/10;
			t=j%10;
			if (s<2||t<2) {
				continue;
			}
			if (s*t==i) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
