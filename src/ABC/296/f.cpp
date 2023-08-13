#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int f(vector<int> a) {
    int n = a.size();
    vector<bool> used(n, false);
    int res = 0;
    rep(sv, n) {
        if (used[sv]) continue;
        int v = sv;
        while (!used[v]) {
            used[v] = true;
            v = a[v];
        }
        res ^= 1;
    }
    return res;
}
bool solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    {
        vector<int> na = a, nb = b;
        sort(na.begin(), na.end());
        sort(nb.begin(), nb.end());
        if (na != nb) return false;
    }
    {
        set<int> s;
        rep(i, n) s.insert(a[i]);
        if (s.size() != n) return true;
    }
    rep(i, n) a[i]--;
    rep(i, n) b[i]--;
    return f(a) == f(b);
}
int main() {
    if (solve())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}