#include <bits/stdc++.h>
using namespace std;

int main(){
	int w,h,x,y;
	cin>>w>>h>>x>>y;
	float ans1;
	int ans2;
	ans1=1.0*w*h/2;
	if (2*x==w&&2*y==h) {
		ans2=1;
	}else {
		ans2=0;
	}
	cout<<ans1<<" "<<ans2<<endl;
}
