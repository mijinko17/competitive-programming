#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    string str;
    vector<int> v;
    map<int, int> mp;
    unordered_map<int, int> um;
    cout << 124 << endl;
    v.push_back(5);
    cout << 5 + 7 << endl;
    v.push_back(5);
    cout << 7 + 8 << endl;
    v.assign(5, 0);
    cout << v[2] << endl;
    v.push_back(7);
    v.push_back(8);
    v.push_back(7);
    v.push_back(2);
    v.push_back(5);
    v.push_back(9);
}
