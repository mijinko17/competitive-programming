#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	long long int p=1e9+7;
	cin>>n>>m;
	int a;
	vector<long long int> dp(n+1,-1);
	for (int i = 0; i < m; i++) {
		cin>>a;
		dp[a]=0;
	}
	dp[0]=1;
	if (dp[1]==-1) {
		dp[1]=1;
	}
	for (int i = 0; i < n-1; i++) {
		if (dp[i+2]==-1) {
			dp[i+2]=dp[i]+dp[i+1];
			dp[i+2]%=p;
		}
	}
	cout<<dp[n]<<endl;
}
