#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	s=s+"X";
	//A,BCのみからなる部分列を考えたい
	//start:部分列の先頭の添字
	//p:部分列の先頭からどれだけ進むか
	//len:部分列の"長さ"(BCをまとめて一文字と思う)
	//numBC:BCの数
	//sumBC:BCの"添字"の和(BCを1文字と思った時の部分列における添字)
	int start=0;
	int p;
	int len;
	long long int numBC;
	long long int sumBC;
	long long int ans=0;
	while (start<s.length()) {
		p=0;
		len=0;
		numBC=0;
		sumBC=0;
		while (s[start+p]=='A'||s.substr(start+p,2)=="BC") {
			if (s[start+p]=='A') {
				p++;
			}else {
				numBC++;
				sumBC+=len;
				p+=2;
			}
			len++;
		}
		ans+=sumBC-numBC*(numBC-1)/2;
		start+=p+1;
	}
	cout<<ans<<endl;
}
