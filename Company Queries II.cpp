// Author: cyberman
// Algorithm: Binary Lifting and Depth

// Approach
//
// Calculate the binary lifting dp
// Calculate the depth of all the nodes
// Then lift the lower node to match both node levels
// Then we use binary lifting dp to lift upto one level below lca
// Then the parent of either nodes is the lca

#include <bits/stdc++.h>
using namespace std;

const int LOG_N = 20; // 2^20 = 1000000

// parent of x, k levels up
int parent(int x, int k, vector<vector<int>> &dp) {
  int pow = 0;
  while (k > 0) {
    if (k & 1) {
      if (x != -1) {
        x = dp[x][pow];
      }
    }
    k = k >> 1;
    pow++;
  }
  return x;
}

void dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &depth,
         int l) {
  depth[node] = l;
  for (int adj : graph[node]) {
    if (adj == parent) {
      continue;
    }
    dfs(adj, node, graph, depth, l + 1);
  }
}

int lca(int a, int b, vector<int> &depth, vector<vector<int>> &dp) {
  // maintain a above b always
  if (depth[a] > depth[b]) {
    int c = a;
    a = b;
    b = c;
  }

  int depthA = depth[a];
  int depthB = depth[b];

  int diff = depthB - depthA;
  for (int i = 0; i <= LOG_N; i++) {
    if (diff & (1 << i)) {
      b = dp[b][i];
    }
  }

  if (a == b) {
    return a;
  }

  for (int k = LOG_N; k >= 0; k--) {
    if (dp[a][k] != dp[b][k]) {
      a = dp[a][k];
      b = dp[b][k];
    }
  }

  return (a != -1 ? dp[a][0] : -1);
}

int main() {
  int n, q;
  cin >> n >> q;

  vector<vector<int>> dp(n + 1, vector<int>(LOG_N + 1, -1));
  vector<vector<int>> graph(n + 1);
  vector<int> depth(n + 1, -1);

  // root = 1, parent of 1 = -1
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    dp[i][0] = x;
    graph[i].push_back(x);
    graph[x].push_back(i);
  }

  for (int k = 1; k <= LOG_N; k++) {
    for (int i = 2; i <= n; i++) {
      if (dp[i][k - 1] != -1) {
        dp[i][k] = dp[dp[i][k - 1]][k - 1];
      }
    }
  }

  dfs(1, -1, graph, depth, 1);

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    int ans = lca(a, b, depth, dp);
    cout << ans << " ";
  }
}