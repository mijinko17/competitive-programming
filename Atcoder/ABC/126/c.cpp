#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	double ans=0;
	double prob;
	int score;
	for (int i = 1; i <=n; i++) {
		score=i;
		prob=1.0/n;
		while (score<k) {
			score*=2;
			prob/=2;
		}
		ans+=prob;
	}
	//printf("%.12f\n",ans);
	cout<<setprecision(12)<<ans<<endl;
}
