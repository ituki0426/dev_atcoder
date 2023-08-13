#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for (int i = 0; i < (n); i++)
mint dp[1002][11][11][11];
int main(void) {
    int n, m;
    cin >> n >> m;
    dp[0][m][m][m] = 1;
    rep(i, n) {
        rep(a1, m + 1) rep(a2, m + 1) rep(a3, m + 1) {
            mint now = dp[i][a1][a2][a3];
            if (now == 0) continue;
            rep(x, m) {
                if (x <= a1)
                    dp[i + 1][x][a2][a3] += now;
                else if (x <= a2)
                    dp[i + 1][a1][x][a3] += now;
                else if (x <= a3)
                    dp[i + 1][a1][a2][x] += now;
            }
        }
    }
    mint ans;
    rep(a1, m) rep(a2, m) rep(a3, m) ans += dp[n][a1][a2][a3];
    cout << ans.val() << endl;
    return 0;
}
