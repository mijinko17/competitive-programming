#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,p;
	int ta,tb,tc;
	int ans;
	int temp;
	long long int inf=1000000000;
	cin>>n>>m>>p;
	vector<int> dist(n,inf);
	dist[0]=0;
	vector<vector<pair<int,int>>> graph(n);
	for (int i = 0; i < m; i++) {
		cin>>ta>>tb>>tc;
		graph[ta-1].push_back(make_pair(tb-1,-(tc-p)));
	}
	for (int i = 0; i < 2*n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				if (dist[j]!=inf&&dist[j]+graph[j][k].second<dist[graph[j][k].first]) {
					dist[graph[j][k].first]=dist[j]+graph[j][k].second;
					if (i>=n) {
						dist[graph[j][k].first]=-inf;
					}
				}
			}
		}
	}
	if (dist[n-1]==-inf) {
		ans=-1;
	}else if (dist[n-1]>0) {
		ans=0;	
	}else {
		ans=-dist[n-1];
	}
	cout<<ans<<endl;
}
