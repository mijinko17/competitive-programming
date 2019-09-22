#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int temp;
	vector<double> inva(n);
	for (int i = 0; i < n; i++) {
		cin>>temp;
		inva[i]=1.0/temp;
	}
	float sum=0;
	for (int i = 0; i < n; i++) {
		sum+=inva[i];
	}
	cout<<1.0/sum<<endl;
}
