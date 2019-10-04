#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n,c;
	cin>>n>>c;
	vector<pair<long long int,long long int>> sushi(n);
	for (int i = 0; i < n; i++) {
		cin>>sushi[i].first>>sushi[i].second;
	}
	long long int ans=0;
	//eatcal_r[i]:時計回りにi個食べた時の摂取カロリー
	vector<long long int> eatcal_r(n+1,0),eatcal_l(n+1,0);
	//max_r[i]:時計回りに0~i個食べた時で、カロリー収支が最大のもの
	vector<long long int> max_r(n+1),max_l(n+1);
	//時計回りに回る時の最大値
	for (int i = 0; i < n; i++) {
		eatcal_r[i+1]=eatcal_r[i]+sushi[i].second;
		max_r[i+1]=max(max_r[i],eatcal_r[i+1]-sushi[i].first);
		ans=max(ans,max_r[i+1]);
	}
	//反時計回りに回る時の最大値
	for (int i = 0; i < n; i++) {
		eatcal_l[i+1]=eatcal_l[i]+sushi[n-1-i].second;
		max_l[i+1]=max(max_l[i],eatcal_l[i+1]-(c-sushi[n-1-i].first));
		ans=max(ans,max_l[i+1]);
	}
	//時計回りにi個食べて折り返す時の最大値
	for (int i = 1; i < n; i++) {
		ans=max(ans,eatcal_r[i]-sushi[i-1].first*2+max_l[n-i]);
	}
	//反時計回りにi個食べて折り返す時の最大値
	for (int i = 1; i < n; i++) {
		ans=max(ans,eatcal_l[i]-(c-sushi[n-i].first)*2+max_r[n-i]);
	}
	cout<<ans<<endl;
}
