#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
int N;
Graph G;
void dfs(int v, int p, int pc, vector<int> &res) {
    int color = 1;
    if (color == pc) color++;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        res[e.second] = color;
        dfs(e.first, v, color, res);
        ++color;
        if (color == pc) ++color;
    }
}
int main() {
    cin >> N;
    G.assign(N, vector<Edge>());
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(Edge(b, i));
        G[b].push_back(Edge(a, i));
    }
    int max_color = 0;
    // 最大次数を求める
    rep(i, N) chmax(max_color, (int)G[i].size());
    vector<int> res(N - 1, -1);
    dfs(0, -1, -1, res);
    cout << max_color << endl;
    rep(i, N - 1) cout << res[i] << endl;
    return 0;
}