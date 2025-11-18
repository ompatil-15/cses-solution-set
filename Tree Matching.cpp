// Author: cyberman
// Algorithm: DP on trees

// Approach
//
// We declare a 2D dp to store two states for each node (pick, notPick)
// dfs traverse the tree and at each node merge the output from all the children
// if we are choosing the current node, select the best candidate for the edge
// such that we maximise 1 + dp[adj][0] + sum - max(dp[adj][0], dp[adj][1])
// we substract that value as we add the max among pick/notPick while
// calculating sum now since we pick the adj which was not picked for the
// current state we substract whatever value it had contributed while
// calculating the sum in case of not picking the current node, we select the
// max of pick/notPick for all the children

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &graph,
         vector<vector<long long>> &dp) {
  long long sum = 0;
  for (int adj : graph[node]) {
    if (adj == parent) {
      continue;
    }
    dfs(adj, node, graph, dp);
    sum += max(dp[adj][0], dp[adj][1]);
  }
  dp[node][0] = sum;

  long long best = 0;
  for (int adj : graph[node]) {
    if (adj == parent) {
      continue;
    }
    long long temp = 1 + dp[adj][0] + sum - max(dp[adj][0], dp[adj][1]);
    best = max(best, temp);
  }
  dp[node][1] = best;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> graph(n + 1);
  vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1, 0, graph, dp);

  cout << max(dp[1][0], dp[1][1]) << "\n";
}