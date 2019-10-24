#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//素因数分解unordered_map版　O(√n)
template <typename T>
unordered_map<T, T> pf_um(T n) {
    unordered_map<T, T> res;
    for (long long int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    if (n != 1) res[n]++;
    return res;
}
//最高位がtopPlaceなブロック数の第place位
char block_number(int block_size, int block_num, int topPlace, int place) {
    place = place + (block_size * block_num - 1) - topPlace;
    if ((place / block_size) % 2 == 0) {
        return '1';
    } else {
        return '0';
    }
}

int main() {
    int n;
    string x;
    cin >> n >> x;
    // topPlace:xを上から見たときに初めて1が現れる位(1の位を0とする)
    int topPlace, top0 = -1;
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            topPlace = n - i - 1;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (x[i] == '0') {
            top0 = n - i - 1;
            break;
        }
    }
    cout << top0 << endl;
    // nを奇数×2冪の形に書く
    int oddPart = n, evenPart = 1;
    while (oddPart % 2 == 0) {
        oddPart /= 2;
        evenPart *= 2;
    }
    // oddPartの1以外の約数全列挙
    vector<int> divisors = {oddPart};
    for (int i = 2; i * i <= oddPart; i++) {
        if (oddPart % i == 0) {
            divisors.push_back(i);
            if (i * i != oddPart) {
                divisors.push_back(oddPart / 2);
            }
        }
    }

    for (int i = 0; i < divisors.size(); i++) {
        // cout << divisors[i] << endl;
    }
    lint ans = 0;
    lint mod = 998244353;
    // numExc:例外処理する数の個数
    int numExc = 0;
    for (int i = 0; i < divisors.size(); i++) {
        int tnumExc = 0;
        int block_size = n / divisors[i];
        int block_num = divisors[i];
        cout << block_size << " " << block_num << endl;
        if (topPlace < n - 1 - block_size) {
            continue;
        }
        // xが最高位topPlaceなブロック数以上か気になる
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (x[j] !=
                block_number(block_size, block_num, topPlace, n - 1 - j)) {
                if (x[j] == '0') {
                    flag = 1;
                }
                break;
            }
        }
        // cout << topPlace << " " << n << " " << block_size << " " << flag
        //    << endl;
        tnumExc = topPlace - n + block_size + 2 - flag;
        cout << tnumExc << endl;
        flag = 1;
        if (top0 != n - 1) {
            if (top0 <= n - 1 - block_size) {
                tnumExc += block_size - 1;
            } else {
                for (int j = 0; j < n; j++) {
                    if (x[j] != block_number(block_size, block_num,
                                             top0 - block_size, n - 1 - j)) {
                        if (x[j] == '0') {
                            flag = 0;
                        }
                        break;
                    }
                }
                tnumExc += n - 2 + top0 + flag;
            }
        }
        // cout << tnumExc << endl;
        lint sub_ans;
        sub_ans = 2 * block_size;
        sub_ans %= mod;
        sub_ans *= tnumExc;
        sub_ans %= mod;
        ans += sub_ans;
        ans %= mod;
        numExc += tnumExc;
        numExc %= mod;
    }
    // cout << ans << endl;
    //答えは大体(x+1)*n*2
    ans += n * 2;
    ans %= mod;
    lint p2 = 1;
    for (int i = 0; i < n; i++) {
        if (x[n - 1 - i] == '1') {
            lint temp = 1;
            temp *= 2 * n;
            temp *= p2;
            ans += temp;
            ans %= mod;
        }
        p2 *= 2;
        p2 %= mod;
    }
    cout << ans << endl;
    //例外処理下部分=numExc*n*2を引く
    int temp = 1;
    temp *= 2 * n;
    temp %= mod;
    cout << numExc << endl;
    temp *= numExc;
    temp %= mod;
    ans -= temp;
    ans %= mod;
    if (ans < 0) {
        cout << ans + mod << endl;
    } else {
        cout << ans << endl;
    }
    for (int i = 0; i < 6; i++) {
        cout << block_number(2, 3, 1, 6 - i - 1);
    }
}
