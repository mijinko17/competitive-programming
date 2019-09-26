#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int a,b;
	cin>>a>>b;
	long long int ans=0;
	long long int left,right;
	if (a%2==0) {
		left=a;
	}else {
		left=a-1;
		ans=ans^left;
	}
	if (b%2==1) {
		right=b;
	}else {
		right=b+1;
		ans=ans^right;
	}
	long long int num1=(right-left+1)/2;
	ans=ans^(num1%2);
	cout<<ans<<endl;
}
