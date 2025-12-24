// Author: cyberman
// Algorithm: Binary lifting, LCA, Math

// Approach
//
// Calculate the depth of noes
// Compute the dp matrix using binary lifting
// Function to calculate LCA using depth and binary lifting
// Use diff array concept from 2D array in trees
// for path u -> v:
// diff[u]++, diff[v]++, diff[lca(u,v)]--, diff[parent[lca(u,v)]]--

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll kLog = 20;

ll lca(ll a, ll b, vector<vector<ll>> &dp, vector<ll> &depth) {
  if (a == b) {
    return a;
  }

  if (depth[a] > depth[b]) {
    swap(a, b);
  }

  // depth of a will now be smaller or equal to b
  ll diff = depth[b] - depth[a];
  for (ll i = 0; i <= kLog; i++) {
    if (diff & (1LL << i)) {
      b = dp[b][i];
    }
  }

  if (a == b) {
    return a;
  }

  for (ll i = kLog; i >= 0; i--) {
    if (dp[a][i] != dp[b][i]) {
      a = dp[a][i];
      b = dp[b][i];
    }
  }
  return dp[a][0];
}

void dfs(ll node, ll parent, vector<vector<ll>> &graph, vector<ll> &depth, ll d,
         vector<vector<ll>> &dp) {
  depth[node] = d;
  for (ll adj : graph[node]) {
    if (adj == parent) {
      continue;
    }
    dfs(adj, node, graph, depth, d + 1, dp);
    dp[adj][0] = node;
  }
}

void dfs2(ll node, ll parent, vector<vector<ll>> &graph, vector<ll> &diff) {
  for (ll adj : graph[node]) {
    if (adj == parent) {
      continue;
    }
    dfs2(adj, node, graph, diff);
    diff[node] += diff[adj];
  }
}

int main() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> graph(n + 1);
  vector<ll> depth(n + 1);
  vector<vector<ll>> dp(n + 1, vector<ll>(kLog + 1, -1));

  for (int i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // find depth of each node and its parent
  dfs(1, -1, graph, depth, 0, dp);

  for (int i = 1; i <= kLog; i++) {
    for (int x = 1; x <= n; x++) {
      // binary lifting
      if (dp[x][i - 1] != -1) {
        dp[x][i] = dp[dp[x][i - 1]][i - 1];
      }
    }
  }

  vector<ll> diff(n + 1, 0);

  for (int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    diff[a]++;
    diff[b]++;
    ll lcaAB = lca(a, b, dp, depth);
    diff[lcaAB]--;
    if (dp[lcaAB][0] != -1) {
      diff[dp[lcaAB][0]]--;
    }
  }

  dfs2(1, -1, graph, diff);

  for (int i = 1; i <= n; i++) {
    cout << diff[i] << (i == n ? '\n' : ' ');
  }
}
