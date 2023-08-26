#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using modint = modint1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
void DFS(Graph &graph, int from, vector<bool> &visited, vector<int> &result) {
    visited[from] = true;

    for (const auto &to : graph[from]) {
        if (!visited[to]) {
            DFS(graph, to, visited, result);
        }
    }
    result.push_back(from);
}

vector<int> TopologicalSort(Graph &graph) {
    vector<int> result;
    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < static_cast<int>(graph.size()); i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, result);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int V, E;
    cin >> V >> E;
    Graph graph(V);
    rep(i, E) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
    }
    const vector<int> result = TopologicalSort(graph);
    for (auto v : result) cout << v << endl;
}