#include <bits/stdc++.h>
using namespace std;

long long int solve(deque<long long int> d,int k, int l,int r){
	long long int sum=0;
	priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
	for (int i = 0; i < l; i++) {
		sum+=d.front();
		pq.push(d.front());
		d.pop_front();
	}
	for (int i = 0; i < r; i++) {
		sum+=d.back();
		pq.push(d.back());
		d.pop_back();
	}
	k-=l+r;
	while (pq.size()>0&&k>0&&pq.top()<0) {
		sum-=pq.top();
		pq.pop();
		k--;
	}
	return sum;
}

int main(){
	int n,k;
	cin>>n>>k;
	deque<long long int> d;
	int temp;
	for (int i = 0; i < n; i++) {
		cin>>temp;
		d.push_back(temp);
	}
	long long int ans=0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if(i+j<=min(n,k)){
				ans=max(ans,solve(d,k,i,j));
			}	
		}
	}
	cout<<ans<<endl;
}
