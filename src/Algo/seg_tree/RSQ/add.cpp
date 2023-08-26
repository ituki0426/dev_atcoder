#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
#define MAX_INT 2147483647

struct SegmentTree {
   private:
    int n;
    vector<int> node;

   public:
    SegmentTree(vector<int> node) {
        int sz = node.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, MAX_INT);

        for (int i = 0; i < sz; i++) node[i + n - 1] = node[i];

        for (int i = n - 2; i >= 0; i--)
            node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }
    void add(int k, int val) {
        k += (n - 1);
        node[k] += val;
        while (k > 0) {
            k = (k - 1) / 2;
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }
};