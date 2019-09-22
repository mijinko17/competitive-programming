#include <bits/stdc++.h>
using namespace std;

int dfs(int n,vector<vector<int>> s,vector<int> push,vector<int> p,int now){
	if (now==n-1) {
		//各電球ごとのスイッチの押された数の計算
		vector<int> tp(p.size(),0);
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s[i].size(); j++) {
				tp[i]+=push[s[i][j]];
				tp[i]%=2;
			}
		}
		if (tp==p) {
			return 1;
		}else {
			return 0;
		}
	}else {
		vector<int> push0=push,push1=push;
		push0[now+1]=0;
		push1[now+1]=1;
		return dfs(n,s,push0,p,now+1)+dfs(n,s,push1,p,now+1);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	int tk,ts;
	vector<vector<int>> s(m);
	for (int i = 0; i < m; i++) {
		cin>>tk;
		for (int j = 0; j < tk; j++) {
			cin>>ts;
			s[i].push_back(ts-1);
		}
	}
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		cin>>p[i];
	}
	vector<int> push(n);
	cout<<dfs(n,s,push,p,-1);
}
