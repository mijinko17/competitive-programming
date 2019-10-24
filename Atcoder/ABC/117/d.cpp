#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

// a^nを計算　O(log n)
long long int powint(long long int a, long long int n) {
    if (n == 0) {
        return 1;
    } else {
        long long int temp = powint(a, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            return temp * temp * a;
        }
    }
}

lint calc(vector<int>& b, int place, lint now, int k, bool d) {
    lint c1, c2;
    c1 =
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(50);
    int now;
    for (int i = 0; i < n; i++) {
        now = 0;
        while (a[i] > 1) {
            if (a[i] % 2 == 1) {
                b[now]++;
            }
            a[i] /= 2;
            now++;
        }
    }
}
