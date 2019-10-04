#include <bits/stdc++.h>
using namespace std;

//now:次何を買うか
long long int dfs(vector<pair<int,vector<int>>>& key,vector<vector<int>>& openable, vector<int> bought, int now){
	if (now==openable.size()) {
		if (bought[11]>1) {
			return 0;
		}else {
			long long int p=1e+10;
			for (int i = 0; i < openable[11].size(); i++) {
				p=min(p,(long long int)key[openable[11][i]].first);
			}
			cout<<p<<endl;
			return p;
		}
	}
	else {
		if (bought[now]>0) {
			return dfs(key,openable,bought,now+1);
		}else {
			long long int p=1e+10;
			for (int i = 0; i < openable[now].size(); i++) {
				vector<int> b;
				for (int j = 0; i < key[openable[now][i]].second.size(); j++) {
					bought[key[openable[now][i]].second[j]]++;
					cout<<j<<endl;
				}
				p=min(p,dfs(key,openable,b,now+1)+key[openable[now][i]].first);
			}
			return p;
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	int ta,tb,tc;
	vector<pair<int,vector<int>>> key(m);
	vector<vector<int>> openable(n);
	for (int i = 0; i < m; i++) {
		cin>>ta>>tb;
		key[i].first=ta;
		for (int j = 0; j < tb; j++) {
			cin>>tc;
			key[i].second.push_back(tc-1);
			openable[tc-1].push_back(i);
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < openable[i].size(); j++) {
			cout<<openable[i][j]<<" ";
		}
		cout<<endl;
	}
	for (int i = 0; i < n; i++) {
		if (openable[i].size()==0) {
			cout<<-1<<endl;
			return 0;
		}
	}
	*/
	vector<int> bought(12,0);
	cout<<dfs(key,openable,bought,0)<<endl;
}
