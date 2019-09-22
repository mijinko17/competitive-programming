#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	int s,t;
	int flag=0;
	cin>>n>>m;
	vector<vector<int>> graph(3*n);
	int tu,tv;
	for (int i = 0; i < m; i++) {
		cin>>tu>>tv;
		for (int j = 0; j < 3; j++) {
			graph[(tu-1+j*n)%(3*n)].push_back((tv-1+(j+1)*n)%(3*n));
		}
	}
	cin>>s>>t;
	int len=0;
	int dest;
	int temp;
	vector<int> reach(3*n,0);
	queue<int> q;
	q.push(s-1);
	while (len<3*n&&q.size()>0&&flag==0) {
		temp=q.size();
		len++;
		for (int i = 0; i < temp; i++) {
			for (int j  = 0; j  < graph[q.front()].size(); j++) {
				dest=graph[q.front()][j];
				if (reach[dest]==0) {
					q.push(dest);
					reach[dest]=1;
					if (reach[t-1]==1) {
						flag=1;
					}
				}
			}
			q.pop();
		}
	}
	if(flag==0){
		cout<<-1<<endl;
	}else {
		cout<<len/3<<endl;
	}
}
