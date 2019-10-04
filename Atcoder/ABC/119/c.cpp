#include <bits/stdc++.h>
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

// aをp進数で表した時の下からn桁目を計算
long long int bit(long long int a, long long int p, long long int n) {
    return (a / powint(p, n)) % p;
}

int main() {
    int n;
    cin >> n;
    vector<int> take(3);
    for (int i = 0; i < 3; i++) {
        cin >> take[i];
    }
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    int M = 1e+9;
    int mp = M;
    int temp;
    vector<int> pretake;
    int pattern = pow(4, n);
    for (int i = 0; i < pattern; i++) {
        temp = 0;
        pretake.assign(3, 0);
        for (int j = 0; j < n; j++) {
            if (bit(i, 4, j) == 3) continue;
            if (pretake[bit(i, 4, j)] > 0) temp += 10;
            pretake[bit(i, 4, j)] += l[j];
        }
        for (int i = 0; i < 3; i++) {
            if (pretake[i] == 0) {
                temp = max(temp, M);
            }
        }
        for (int i = 0; i < 3; i++) {
            temp += abs(pretake[i] - take[i]);
        }
        mp = min(mp, temp);
    }
    cout << mp << endl;
}
