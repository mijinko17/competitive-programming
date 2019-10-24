#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//累積和
struct cumulative_sum {
    // data[i]:[0,i)の和
    vector<long long int> data;
    //コンストラクタ O(n)
    template <typename T>
    cumulative_sum(vector<T>& v) {
        data.assign(v.size() + 1, 0);
        for (int i = 0; i < (int)v.size(); i++) {
            data[i + 1] = data[i] + v[i];
        }
    }
    //[a,b)の和を求める
    const long long int sum(long long int a, long long int b) {
        return data[b] - data[a];
    }
};

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    int a;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a;
        }
    }
}
