// Author: cyberman
// Algorithm: Tree Distances I (Diameter method)

#include <bits/stdc++.h>
using namespace std;

pair<int, int> f(int node, int parent, int dist, vector<vector<int>> &graph) {
  pair<int, int> res = {dist, node};

  for (int adj : graph[node]) {
    if (adj == parent)
      continue;
    res = max(res, f(adj, node, dist + 1, graph));
  }
  return res;
}

void dfs(int node, int parent, int dist, vector<vector<int>> &graph,
         vector<int> &ans) {
  ans[node] = max(ans[node], dist);

  for (int adj : graph[node]) {
    if (adj == parent)
      continue;
    dfs(adj, node, dist + 1, graph, ans);
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> graph(n + 1);
  vector<int> ans(n + 1, 0);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  auto [d1, u] = f(1, -1, 0, graph);

  auto [diameter, v] = f(u, -1, 0, graph);

  dfs(u, -1, 0, graph, ans);
  dfs(v, -1, 0, graph, ans);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }
}