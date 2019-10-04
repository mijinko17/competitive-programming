#include <iostream>
#include <vector>
using namespace std;

//a^n mod pを計算　O(log n)
long long int powmod(long long int a, long long int n, long long int p)
{
	if (n == 1){
		return a;
	}else{
		long long int temp = powmod(a, n / 2, p);
		if (n % 2 == 0){
			return (temp * temp) % p;
		}else{
			return (((temp * temp) % p) * a) % p;
		}
	}
}

//Z_pでのaの逆元を計算 O(log p)
long long int inv(long long int a, long long int p){
	return powmod(a, p - 2, p);
}

int main(){
	for (int i = 0; i < 13; i++) {
		cout<<inv(i,13)<<endl;
	}
}
