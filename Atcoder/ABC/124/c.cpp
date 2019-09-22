#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int dist=0;
	//10101...に揃えるときの塗り替え数を計算
	for (int i = 0; i < s.length(); i++) {
		if (i%2==0) {
			if (s[i]=='0') {
				dist++;
			}
		}else {
			if (s[i]=='1') {
				dist++;
			}
		}
	}
	//01010...に塗る＝s.length()-dist
	cout<<min(dist,(int)s.length()-dist)<<endl;
}
