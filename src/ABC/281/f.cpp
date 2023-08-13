#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    auto f = [&](auto f, const vector<int>& a, int k) -> int {
        if (k == -1) return 0;
        vector<int> l, r;
        for (auto x : a) {
            if (x >> k & 1)
                r.push_back(x ^ 1 << k);
            else
                l.push_back(x);
        }
        if (l.size() == 0) return f(f, r, k - 1);
        if (r.size() == 0) return f(f, l, k - 1);
        return min(f(f, l, k - 1), f(f, r, k - 1)) + (1 << k);
    };
    cout << f(f, a, 29) << endl;
    return 0;
}