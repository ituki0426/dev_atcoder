#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n), b(n), c(m), d(m);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, m) cin >> c[i] >> d[i];
    rep(i, n) b[i] += a[i];
    rep(i, m) d[i] += c[i];
    double ac = 0;
    double wa = 1;
    auto f = [&](double x) {
        vector<double> s(n);
        vector<double> t(m);
        rep(i, n) s[i] = a[i] - b[i] * x;
        rep(i, m) t[i] = d[i] * x - c[i];
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int j = 0;
        ll res = 0;
        rep(i, n) {
            while (j < m && t[j] < s[i]) j++;
            res += j;
        }
        return res;
    };
    rep(ti, 80) {
        double wj = (ac + wa) / 2;
        if (f(wj) >= k)
            ac = wj;
        else
            wa = wj;
    }
    printf("%.10f\n", ac * 100);
    return 0;
}