#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//ただの辺
struct edge {
    using lint = long long int;
    int to;
    lint cost;
    //引数一つの時は距離1
    edge(int t, lint c = 1) : to(t), cost(c) {
    }
};

struct info {
    int from;
    int now;
    int color;
    info(int _from, int _now,int _color) : from(_from), now(_now),color(_color) {
    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<edge>> g(n);
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back(edge(b,i));
        g[b].push_back(edge(a,i));
    }
    vector<int> ans(n-1,-1);
    //first:from,second:now
    queue<info> bfs;
    bfs.push(info(-1,0,0));
    while (!bfs.empty()) {
        info temp=bfs.front();
        bfs.pop();
        int usecolor=1;
        for (int i = 0; i < g[temp.now].size(); i++) {
            int next=g[temp.now][i].to;
            if (next==temp.from) {
                continue;
            }
            if (usecolor==temp.color) {
                usecolor++;
            }
            ans[g[temp.now][i].cost]=usecolor;
            bfs.push(info(temp.now,next,usecolor));
            usecolor++;
        }
    }
    cout<<*max_element(all(ans))<<endl;
    for (int i = 0; i < n-1; i++) {
        cout<<ans[i]<<endl;
    }
}
