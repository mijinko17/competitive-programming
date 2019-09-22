#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	int now=0;
	vector<int> comp;
	//両端を逆立ちと思いたいその1
	if (s[0]=='0') {
		comp.push_back(0);
		now++;
	}
	//連結成分の長さをベクターに突っ込む
	comp.push_back(1);
	for (int i = 1; i < n; i++) {
		if (s[i]==s[i-1]) {
			comp[now]++;
		}else {
			comp.push_back(1);
			now++;
		}
	}
	//両端を逆立ちと思いたいその2
	if (s[n-1]=='0') {
		comp.push_back(0);
	}
	priority_queue<int> cand;
	//初期状態を作る
	int temp=0;
	for (int i = 0; i < min(2*k+1,(int)comp.size()); i++) {
		temp+=comp[i];
	}
	cand.push(temp);
	int left=0;
	int right=min(2*k+1,(int)comp.size())-1;
	//候補を突っ込みまくる
	while (right+1<comp.size()) {
		temp+=comp[right+1]+comp[right+2]-comp[left]-comp[left+1];
		cand.push(temp);
		left+=2;
		right+=2;
	}
	cout<<cand.top()<<endl;
}
