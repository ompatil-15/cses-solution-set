// Author: cyberman
// Algorithm: DFS with backtracking

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(ll node, ll parent, unordered_map<ll, vector<ll>> &graph, vector<ll> &path, vector<bool> &vis, bool &found) {
    vis[node] = true;
    path.push_back(node);

    for (auto adj : graph[node]) {
        if (!vis[adj]) {
            dfs(adj, node, graph, path, vis, found);
            if (found) return;
        } else if (adj != parent) {
            path.push_back(adj);
            found = true;
            return;
        }
    }

    path.pop_back();
}

int main() {
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, vector<ll>> graph;

    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    vector<ll> path;
    bool found = false;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, -1, graph, path, vis, found);
            if (found) break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        ll start = path.back();
        vector<ll> cycle;
        cycle.push_back(start);
        for (int i = path.size() - 2; i >= 0; i--) {
            cycle.push_back(path[i]);
            if (path[i] == start) break;
        }
        cout << cycle.size() << endl;
        for (auto node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}