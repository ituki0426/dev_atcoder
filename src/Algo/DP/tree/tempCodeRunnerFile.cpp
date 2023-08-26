// Atcoder Beginner Contest 259 F(青diff)
#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using Edge = pair<int, ll>;
using Graph = vector<vector<Edge>>;
const ll INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    rep(i, N) cin >> d[i];
    Graph G(N);
    rep(i, N - 1) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }
    vector<ll> dpfull(N, -INF);
    vector<ll> dprem(N, -INF);
    auto rec = [&](auto self, const Graph &G, int v, int p) -> void {
        ll base = 0;
        vector<ll> diff;
        for (auto e : G[v]) {
            if (e.first == p) continue;
            self(self, G, e.first, v);
            base += dpfull[e.first];
            diff.push_back(e.second + dprem[e.first] - dpfull[e.first]);
        }

        ll fulladd = 0;
        ll remadd = 0;
        sort(diff.begin(), diff.end(), greater<ll>());
        for (int i = 0; i < min(d[v], (int)diff.size()) && diff[i] >= 0; i++) {
            fulladd += diff[i];
            if (i < d[v] - 1) remadd += diff[i];
        }

        dpfull[v] = base + fulladd;
        if(d[v]) dprem[v] = base + remadd;
    };

    rec(rec, G, 0, -1);

    cout << dpfull[0] << endl;
    return 0;
}