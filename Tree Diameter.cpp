// Author: cyberman
// Algorithm: Tree traversal

// Approach
//
// First we find the farthest node (t) from a random starting node (s)
// We then find the farthest node (v) from t
// t->v is the diameter of the tree
// We are gauranteed that t is one of the diameter edge
// As if it was not s -> t > s -> u and s -> v
// consider u -> v diameter
// There will be come common path between all three before diverging
// Now if t was not u, v, then it would violate the fact that u -> v is diameter

#include <bits/stdc++.h>
using namespace std;

pair<int, int> f(int node, int parent, int dist, vector<vector<int>> &graph) {
  pair<int, int> res = {dist, node};

  for (int adj : graph[node]) {
    if (adj == parent) {
      continue;
    }
    pair<int, int> temp = f(adj, node, dist + 1, graph);
    res = max(res, temp);
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> graph(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  auto [temp_d, start] = f(1, -1, 0, graph);
  auto [diameter, end] = f(start, -1, 0, graph);

  cout << diameter << "\n";
}