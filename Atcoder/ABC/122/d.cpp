#include <bits/stdc++.h>
using namespace std;

string is3(int n){
	vector<string> v={"A","C","G","T"};
	return v[(n%64)/16]+v[(n%16)/4]+v[n%4];
}
string is4(int n){
	vector<string> v={"A","C","G","T"};
	return v[n/64]+v[(n%64)/16]+v[(n%16)/4]+v[n%4];
}
int si(string s){
	unordered_map<char,int> m;
	m['A']=0;
	m['C']=1;
	m['G']=2;
	m['T']=3;
	return m[s[0]]+4*m[s[1]]+16*m[s[2]];
}
bool agc3(string s){
	//return s!="AGC"&&s!="ACG"&&s!="GAC";
	return s=="AGC"||s=="ACG"||s=="GAC";
}
bool agc4(string s){
	string s1,s2;
	s1=s.substr(0,3);
	s1[2]=s[3];
	s2=s.substr(1,3);
	s2[0]=s[0];
	return agc3(s.substr(0,3))||agc3(s.substr(1,3))||agc3(s1)||agc3(s2);
}

int main(){
	int ans=0;
	for (int i = 0; i < 256; i++) {
		if (!agc4(is4(i))) {
			ans++;
		}else {
			cout<<is4(i)<<endl;
		}
	}
	cout<<ans<<endl;
}
