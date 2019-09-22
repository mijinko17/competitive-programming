#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;
	list<pair<int,int>> cand;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (s[i]==s[j]) {
				cand.push_back(make_pair(i,j));
			}
		}
	}
	int len=0;
	int first,second;
	if (cand.size()==0) {
		cout<<0<<endl;
	}else {
		while (cand.size()>0) {
			len++;
			for (auto itr = cand.begin(); itr !=cand.end(); itr++) {
				first=(*itr).first;
				second=(*itr).second;

				if (second>=n-len) {
					cand.erase(itr);
				}else if (s[first+len]!=s[second+len]) {
					cand.erase(itr);
				}
			}
		}
		cout<<len<<endl;
	}
}
