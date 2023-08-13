#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n + 1);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    const int INF = 1001001001;
    auto f = [&](int sv) {
        vector<int> dist(n + 1, INF);
        queue<int> q;
        q.push(sv);
        dist[sv] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : to[v]) {
                if (dist[u] != INF) continue;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
        return dist;
    };
    vector<int> d1 = f(1), dn = f(n);
    for (int i = 1; i <= n; i++) {
        int ans = d1[n];
        ans = min(ans, d1[i] + dn[0]);
        ans = min(ans, d1[0] + dn[i]);
        if (ans == INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}