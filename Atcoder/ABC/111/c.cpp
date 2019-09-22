#include <bits/stdc++.h>
using namespace std;

int secondelement(int a,int b, int c){
	vector<int> temp={a,b,c};
	sort(temp.begin(),temp.end());
	return temp[1];
}

int main(){
	int n;
	cin>>n;
	vector<int> vo(n/2),ve(n/2);
	for (int i = 0; i < n; i++) {
		if (i%2==0) {
			cin>>ve[i/2];
		}else {
			cin>>vo[i/2];
		}
	}
	//veの最頻値、第二最頻値を調べる
	int mi,si;
	int mv,sv;
	unordered_map<int,int> ume,umo;
	for (int i = 0; i < n/2; i++) {
		ume[ve[i]]++;
		umo[vo[i]]++;
	}
	unordered_map<int,int>::iterator itr1,itr2;
	if ((*ume.begin()).second>=(*next(ume.begin())).second) {
		itr1=ume.begin();
		itr2=next(ume.begin());
	}
	for (auto itr = ume.begin(); itr !=ume.end(); itr++) {
		//cout<<(*itr).second<<endl;
	}
}
