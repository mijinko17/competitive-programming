#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	if (n%2==0) {
		cout<<0.5<<endl;
	}else {
		cout<<1.0*(n+1)/2/n<<endl;
	}
}
