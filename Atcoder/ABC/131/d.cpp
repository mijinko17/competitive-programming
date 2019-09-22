#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> ab(n);
	int ta,tb;
	for (int i = 0; i < n; i++) {
		cin>>ta>>tb;
		ab[i]=make_pair(ta,tb);
	}
	sort(
		ab.begin(),
		ab.end(),
		[](const pair<int,int>& x,const pair<int,int>& y){return x.second<y.second;}
	);
	long long int time=0;
	auto itr=ab.begin();
	while(itr!=ab.end()){
		time+=(*itr).first;
		if (time<=(*itr).second) {
			itr++;
		}else {
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}
