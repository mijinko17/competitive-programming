#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<vector<pair<int,int>>>> g(n,vector<vector<pair<int,int>>>(n));
	vector<vector<int>> c(n,vector<int>(n,0));
	//game1:優先される試合
	int tmp1=0;
	int tmp2=0;
	pair<int,int> game1,game2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			tmp2=tmp1;
			cin>>tmp1;
			if (j>0) {
				game1=make_pair(min(i,tmp2-1),max(i,tmp2-1));
				game2=make_pair(min(i,tmp1-1),max(i,tmp1-1));
				g[game1.first][game1.second].push_back(game2);
				c[game2.first][game2.second]++;
			}
		}
	}
	//湧き出しを探す
	int count=0;
	queue<pair<int,int>> q;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (c[i][j]==0) {
				q.push(make_pair(i,j));
				count++;
			}
		}
	}
	//bfs
	int task;
	int day=0;
	pair<int,int> dest,source;
	while (q.size()>0) {
		task=q.size();
		for (int i = 0; i < task; i++) {
			source=q.front();
			for (int j = 0; j < g[source.first][source.second].size(); j++) {
				dest=g[source.first][source.second][j];
				c[dest.first][dest.second]--;
				if (c[dest.first][dest.second]==0) {
					q.push(dest);
					count++;
				}
			}
			q.pop();
		}
		day++;
	}
	if (count==n*(n-1)/2) {
		cout<<day<<endl;
	}else {
		cout<<-1<<endl;
	}
}
