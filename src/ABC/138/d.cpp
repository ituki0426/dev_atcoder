#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;

int main(void) {
    int N, Q;
    cin >> N >> Q;
    vector<int> seen(N);
    Graph G(N);
    auto dfs = [&]()
}
