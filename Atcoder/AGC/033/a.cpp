#include <bits/stdc++.h>
using namespace std;

int main(){
	int h,w;
	cin>>h>>w;
	vector<vector<int>> a(h,vector<int>(w));
	char temp;
	queue<pair<int,int>> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin>>temp;
			if (temp=='#') {
				a[i][j]=1;
				q.push(make_pair(i,j));
			}else {
				a[i][j]=0;
			}
		}
	}
	int task;
	int x,y;
	while (q.size()>0) {
		task=q.size();
		for (int i = 0; i < task; i++) {
			x=q.front().first;
			y=q.front().second;
			if () {
				
			}
		}
	}
}
