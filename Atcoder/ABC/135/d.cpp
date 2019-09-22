#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	long long int m=1e9+7;
	int pow=1;
	int n;
	cin>>s;
	n=s.size();
	vector<vector<long long int>> dp(n,vector<long long int>(13));
	if(s[n-1]=='?'){
		for (int i = 0; i < 10; i++) {
			dp[0][i%13]++;	
		}
	}else {
		dp[0][s[n-1]-'0']++;
	}
	for (int i = 1; i < s.size(); i++) {
		pow*=10;
		pow%=13;
		if(s[n-i-1]=='?'){
			for (int j = 0; j < 13; j++) {
				for (int k = 0; k < 10; k++) {
					dp[i][(j+k*pow)%13]+=dp[i-1][j];
					dp[i][(j+k*pow)%13]%=m;
				}
			}
		}else {
			for (int j = 0; j < 13; j++) {
				dp[i][(j+(s[n-i-1]-'0')*pow)%13]+=dp[i-1][j];
				dp[i][(j+(s[n-i-1]-'0')*pow)%13]%=m;
			}
		
		}
	}
	cout<<dp[n-1][5]<<endl;
}
