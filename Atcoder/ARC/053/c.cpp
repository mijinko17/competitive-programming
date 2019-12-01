#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    //最終的に気温が上がる魔法と下がる魔法で分ける
    vector<pair<lint, lint>> m_pos, m_neg;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a - b <= 0) {
            m_neg.push_back({a, b});
        } else {
            m_pos.push_back({a, b});
        }
    }
    //負の魔法はaが小さい順に行うのが最適
    auto c_neg = [](const pair<lint, lint> x, const pair<lint, lint> y) {
        return x.first < y.first;
    };
    //正の魔法はbが大きい順に行うのが最適
    auto c_pos = [](const pair<lint, lint> x, const pair<lint, lint> y) {
        return x.second > y.second;
    };
    sort(all(m_neg), c_neg);
    sort(all(m_pos), c_pos);
    //シミュレーション
    lint x = 0, now = 0;
    for (int i = 0; i < m_neg.size(); i++) {
        auto temp = m_neg[i];
        x = max(x, now + temp.first);
        now = now + temp.first - temp.second;
    }
    for (int i = 0; i < m_pos.size(); i++) {
        auto temp = m_pos[i];
        x = max(x, now + temp.first);
        now = now + temp.first - temp.second;
    }
    cout << x << endl;
}
