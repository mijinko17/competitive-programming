#include <bits/stdc++.h>
using namespace std;

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
	//出現頻度の測定
	unordered_map<int,int> ume,umo;
	for (int i = 0; i < n/2; i++) {
		ume[ve[i]]++;
		umo[vo[i]]++;
	}
	//最頻値の計算
	unordered_map<int,int>::iterator eitr1,eitr2;
	int em=0,es=0;
	for (auto itr = ume.begin(); itr !=ume.end(); itr++) {
		if ((*itr).second>=em) {
			eitr1=itr;
			em=(*itr).second;
		}
	}
	for (auto itr = ume.begin(); itr !=ume.end(); itr++) {
		if (itr==eitr1) {
			continue;
		}
		if ((*itr).second>=es) {
			eitr2=itr;
			es=(*itr).second;
		}
	}
	unordered_map<int,int>::iterator oitr1,oitr2;
	int om=0,os=0;
	for (auto itr = umo.begin(); itr !=umo.end(); itr++) {
		if ((*itr).second>=om) {
			oitr1=itr;
			om=(*itr).second;
		}
	}
	for (auto itr = umo.begin(); itr !=umo.end(); itr++) {
		if (itr==oitr1) {
			continue;
		}
		if ((*itr).second>=os) {
			oitr2=itr;
			os=(*itr).second;
		}
	}
	int ans;
	if ((*eitr1).first!=(*oitr1).first) {
		ans=n-em-om;
	}else {
		ans=min(n-em-os,n-om-es);
	}
	cout<<ans<<endl;
}
