#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint simulation_1(vector<lint> start, vector<pair<lint, lint>> &formula) {
    lint itr = 13;
    int n = start.size();
    for (int z = 0; z < itr; z++) {
        for (int i = 0; i < n; i++) {
            start[formula[i].first] += start[i];
            start[formula[i].second] += start[i];
            start[i] = 0;
        }
    }
    lint now = start[0];
    for (int i = 0; i < n; i++) {
        start[formula[i].first] += start[i];
        start[formula[i].second] += start[i];
        start[i] = 0;
    }
    if (now < start[0]) {
        return LLONG_MAX;
    } else {
        return start[0];
    }
}
lint simulation_2(vector<lint> start, vector<pair<lint, lint>> &formula) {
    lint itr = 13;
    int n = start.size();
    for (int z = 0; z < itr; z++) {
        for (int i = 1; i < n; i++) {
            start[formula[i].first] += start[i];
            start[formula[i].second] += start[i];
            start[i] = 0;
        }
    }
    int now = start[0];
    for (int i = 1; i < n; i++) {
        start[formula[i].first] += start[i];
        start[formula[i].second] += start[i];
        start[i] = 0;
    }
    if (now < start[0]) {
        return LLONG_MAX;
    } else {
        return start[0];
    }
}

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        int m;
        cin >> m;
        vector<pair<lint, lint>> formula(m);
        for (int i = 0; i < m; i++) {
            cin >> formula[i].first >> formula[i].second;
            formula[i].first--;
            formula[i].second--;
        }
        vector<lint> start(m);
        for (int i = 0; i < m; i++) {
            cin >> start[i];
        }
        lint ans = max(simulation_1(start, formula), simulation_2(start, formula));
        if (ans == LLONG_MAX) {
            cout << "UNBOUNDED" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
