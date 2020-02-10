#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> b(n);
	int tx,ty;
	for (int i = 0; i < n; i++) {
		cin>>tx>>ty;
		b[i]=make_pair(tx,ty);
	}
	int p,q;
	int dx,dy;
	int ans=n;
	int temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			p=b[i].first-b[j].first;
			q=b[i].second-b[j].second;
			temp=n;
			for (int k = 0; k < n-1; k++) {
				for (int l = k+1; l < n; l++) {
					dx=b[k].first-b[l].first;
					dy=b[k].second-b[l].second;
					if ((dx==p&&dy==q)||(dx==-p&&dy==-q)) {
						temp--;
					}
				}
			}
			ans=min(ans,temp);
		}
	}
	cout<<ans<<endl;
}
