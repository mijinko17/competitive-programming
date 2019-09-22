#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;
	vector<vector<int>> graph(n);
	int ta,tb;
	for (int i = 0; i < n-1; i++) {
		cin>>ta>>tb;
		graph[ta-1].push_back(tb-1);
		graph[tb-1].push_back(ta-1);
	}
	vector<int> p(q);
	vector<int> x(q);
	vector<long long int> c(n,0);
	for (int i = 0; i < q; i++) {
		cin>>p[i]>>x[i];
		c[p[i]-1]+=x[i];
	}
	queue<int> qu;
	qu.push(0);
	int task;
	int child;
	vector<int> checked(n,0);
	checked[0]=1;
	while (qu.size()>0) {
		task=qu.size();
		for (int i = 0; i < task; i++) {
			for (int j = 0; j < graph[qu.front()].size(); j++) {
				child=graph[qu.front()][j];
				if (checked[child]==0) {
					c[child]+=c[qu.front()];
					checked[child]=1;
					qu.push(child);
				}
			}
			qu.pop();
		}
	}
	for (int i = 0; i < n; i++) {
		cout<<c[i]<<" ";
	}
	cout<<endl;
}
