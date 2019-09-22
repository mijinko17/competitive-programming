#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<pair<int,int>>>& graph,vector<int>& color,int from, int now){
	pair<int,int> edge;
	for (int i = 0; i < graph[now].size(); i++) {
		edge=graph[now][i];
		if (edge.first==from) {
			continue;
		}
		if (edge.second%2==0) {
			color[edge.first]=color[now];
		}else {
			color[edge.first]=(color[now]+1)%2;
		}
		solve(graph,color,now,edge.first);
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<pair<int,int>>> graph(n);
	int tu,tv,tw;
	for (int i = 0; i < n-1; i++) {
		cin>>tu>>tv>>tw;
		graph[tu-1].push_back(make_pair(tv-1,tw));
		graph[tv-1].push_back(make_pair(tu-1,tw));
	}
	vector<int> color(n,-1);
	color[0]=0;
	solve(graph,color,-1,0);
	for (int i = 0; i < n; i++) {
		cout<<color[i]<<endl;
	}
}
