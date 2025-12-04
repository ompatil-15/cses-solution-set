#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<int> depth(n + 1);
  vector<vector<int>> up(n + 1, vector<int>(LOG + 1));

  // BFS for depth & parent
  queue<int> qu;
  qu.push(1);
  depth[1] = 0;
  up[1][0] = -1;

  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    for (int v : graph[u]) {
      if (v == up[u][0])
        continue;
      depth[v] = depth[u] + 1;
      up[v][0] = u;
      qu.push(v);
    }
  }

  // Build binary lifting table
  for (int k = 1; k <= LOG; k++) {
    for (int i = 1; i <= n; i++) {
      if (up[i][k - 1] == -1)
        up[i][k] = -1;
      else
        up[i][k] = up[up[i][k - 1]][k - 1];
    }
  }

  auto lca = [&](int a, int b) {
    if (depth[a] < depth[b])
      swap(a, b);
    int diff = depth[a] - depth[b];

    for (int k = 0; k <= LOG; k++)
      if (diff & (1 << k))
        a = up[a][k];

    if (a == b)
      return a;

    for (int k = LOG; k >= 0; k--) {
      if (up[a][k] != up[b][k]) {
        a = up[a][k];
        b = up[b][k];
      }
    }
    return up[a][0];
  };

  auto dist = [&](int u, int v) {
    int c = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[c];
  };

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << dist(a, b) << " ";
  }
}
