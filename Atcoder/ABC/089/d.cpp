#include <bits/stdc++.h>
using namespace std;

int md(pair<int,int> a,pair<int,int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(){
	//マスに入れる数字を0~h*w-1と思う
	int h,w,d;
	cin>>h>>w>>d;
	vector<pair<int,int>> b(h*w);
	int ta;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin>>ta;
			b[ta-1]=make_pair(i,j);
		}
	}
	int q;
	cin>>q;
	vector<pair<int,int>> query(q);
	int tl,tr;
	for (int i = 0; i < q; i++) {
		cin>>tl>>tr;
		query[i]=make_pair(tl-1,tr-1);
	}
	//mp[i][j]:iからj回移動するのに掛かる魔力
	vector<vector<int>> mp(d,vector<int>(h*w/d+1,0));
	for (int i = 0; i < d; i++) {
		for (int j = 1; i+j*d<h*w; j++) {
			mp[i][j]=mp[i][j-1]+md(b[i+d*(j-1)],b[i+d*j]);
		}
	}
	int start;
	int step1,step2;
	for (int i = 0; i < q; i++) {
		start=query[i].first%d;
		step1=query[i].first/d;
		step2=query[i].second/d;
		cout<<mp[start][step2]-mp[start][step1]<<endl;
	}
}
