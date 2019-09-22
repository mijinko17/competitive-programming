#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> s(n),t(m);
	for (int i = 0; i < n; i++) {
		cin>>s[i];
	}
	for (int i = 0; i < m; i++) {
		cin>>t[i];
	}
	//dp[i][j]:s[0]~s[i]の部分列とTとの共通部分列であって、tでの右端がt[j]なるものの数
	vector<vector<int>> dp(n,vector<int>(n,0));
	//dp[0][j]の計算
	for (int j = 0; j < n; j++) {
		if (s[0]==t[j]) {
			dp[0][j]++;
		}
	}
	//dp[i][j]をdpで決定
	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k < j; k++) {
				if (s[i]==t[k]) {
					dp[i][j]+=dp[i-1][k-1];
				}
			}
		}
	}
}
