#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using Graph = vector<vector<int>>;  // グラフ型
// 辞書順最小のトポロジカルソートの結果を得る
vector<int> TopologicalSort(Graph &graph) {
    vector<int> in_degree(graph.size(), 0);

    for (const auto &from : graph)
        for (const auto &to : from) in_degree[to]++;

    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, (int)graph.size()) if (in_degree[i] == 0) pq.push(i);
    vector<int> result;
    while (!pq.empty()) {
        const int from = pq.top();
        pq.pop();
        result.push_back(from);
        for (const auto &to : graph[from])
            if (--in_degree[to] == 0) pq.push(to);
    }
    if (result.size() != graph.size()) return {};
    return result;
}
int main() {
    int V, E;
    cin >> V >> E;
    Graph graph(V);
    rep(i, E) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        graph[s].push_back(t);
    }
    const vector<int> result = TopologicalSort(graph);
    if (result.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (const auto v : result) cout << v + 1 << ' ';
    cout << endl;
    return 0;
}