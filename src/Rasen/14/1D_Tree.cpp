#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const static int MAX = 1000000;
struct Node {
    int location;
    int p, l, r;
    Node() {}
};
Node T[MAX];
int np;
int make1DTree(int l, int r) {
    if (!(l < r)) return -1;
    int mid = (l + r) / 2;
    int t = np++;
    T[t].location = mid;
    T[t].l = make1DTree(l, mid);
    T[t].r = make1DTree(mid + 1, r);
    return t;
}
int main() {
    cout << "go" << endl;
    return 0;
}