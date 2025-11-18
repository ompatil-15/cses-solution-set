// Author: cyberman
// Algorithm: DFS with edge reversal

// Approach
//
// We need to check for Strongly Connected Component (SCC)
// We can test this by using a bridge node
// contracting scc -> directed acyclic graph    

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &vis) {
    if (vis[node]) return;
    vis[node] = true;
    for (int adj : graph[node]) {
        dfs(adj, graph, vis);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<vector<int>> reverseGraph(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    
    dfs(1, graph, vis);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO" << "\n";
            cout << 1 << " " << i << "\n";
            return 0;
        }
        vis[i] = false;
    }

    dfs(1, reverseGraph, vis);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO" << "\n";
            cout << i << " " << 1 << "\n";
            return 0;
        }
        vis[i] = false;
    }

    cout << "YES" << "\n";
}