#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using Graph = vector<vector<int>>;

// トポロジカルソート

vector<int> topological_sort(Graph &G, vector<int> &indegree, int V) {
    vector<int> sorted_vertices;
    queue<int> que;
    rep(i, V) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u]--;
            if (indegree[u] == 0) que.push(u);
        }
        sorted_vertices.push_back(v);
    }
    return sorted_vertices;
}

int main() {
    int V, E;
    cin >> V >> E;
    Graph G(V);
    // 入次数
    vector<int> indeg(V, 0);
    rep(i, E) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        indeg[v]++;
    }
    vector<int> sorted_vertices = topological_sort(G, indeg, V);
    rep(i, sorted_vertices.size()) cout << sorted_vertices[i] << endl;
    return 0;
}