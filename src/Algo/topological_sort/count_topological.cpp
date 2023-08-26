#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
vector<vector<bool>> bad(16, vector<bool>(16, false));
vector<ll> dp(1 << 16, 0);

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        bad[y][x] = true;
    }
    dp[0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!(1 & (i >> j))) {
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (1 & (i >> k))
                        if (bad[k][j]) ok = false;
                }
                if (ok) dp[i + (1 << j)] += dp[i];
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}


