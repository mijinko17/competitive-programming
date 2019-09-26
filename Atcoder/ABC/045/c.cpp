#include <bits/stdc++.h>
using namespace std;

long long int calc(string s,int b){
	int n=s.length();
	long long int val=0;
	for (int i = 0; i < n-1; i++) {
		val+=stoi(s.substr(0,i+1))+calc(s.substr(i+1));
	}
	val+=stoi(s);
	cout<<val<<endl;
	return val;
}

int main(){
	string s;
	cin>>s;
	cout<<calc(s,0)<<endl;
}
