// Author: cyberman
// Algorithm: Re-rooting DP

// Approach
//
// Calculate the ans with root 1
// In the next dfs re-root to calculate the ans for all the children

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs1(int node, int parent, vector<vector<int>> &graph,
          vector<int> &subTree, vector<ll> &dp) {
  subTree[node] = 1;
  for (int adj : graph[node]) {
    if (adj == parent) {
      continue;
    }
    dfs1(adj, node, graph, subTree, dp);
    dp[node] += dp[adj] + subTree[adj];
    subTree[node] += subTree[adj];
  }
}

void dfs2(int node, int parent, vector<vector<int>> &graph,
          vector<int> &subTree, vector<ll> &dp, vector<ll> &ans) {
  ans[node] = dp[node];
  for (int adj : graph[node]) {
    if (adj == parent) {
      continue;
    }
    ll dp_node = dp[node];
    ll dp_adj = dp[adj];
    int subTree_node = subTree[node];
    int subTree_adj = subTree[adj];

    dp[node] -= dp[adj] + subTree[adj];
    subTree[node] -= subTree[adj];

    dp[adj] += dp[node] + subTree[node];
    subTree[adj] += subTree[node];

    dfs2(adj, node, graph, subTree, dp, ans);

    dp[node] = dp_node;
    dp[adj] = dp_adj;
    subTree[node] = subTree_node;
    subTree[adj] = subTree_adj;
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> graph(n + 1);
  vector<int> subTree(n + 1, 0);
  vector<ll> dp(n + 1, 0);
  vector<ll> ans(n + 1, 0);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs1(1, -1, graph, subTree, dp);
  dfs2(1, -1, graph, subTree, dp, ans);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? "\n" : " ");
  }
}