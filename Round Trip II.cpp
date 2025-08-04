// Author: cyberman
// Algorithm: DFS

// Approach
// 1. start a dfs from each node
// 2. keep track of the parent of nodes and nodes in the current path
// 3. when we come across a node that is visited before that means cycle exists
// 4. start_node -> cycle_start -> cycle_end -> cycle_start
// 5. if we find a cycle print the cycle using traversing through parent and reversing the path

#include <bits/stdc++.h>
using namespace std;

vector<int> vis, inStack, parent;
int cycle_start = -1, cycle_end = -1;

bool dfs(int node, const vector<vector<int>> &graph) {
    vis[node] = 1;
    inStack[node] = 1;

    for (int neighbor : graph[node]) {
        if (!vis[neighbor]) {
            parent[neighbor] = node;
            if (dfs(neighbor, graph)) return true;
        } else if (inStack[neighbor]) {
            // Back edge detected
            cycle_end = node;
            cycle_start = neighbor;
            return true;
        }
    }

    inStack[node] = 0;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vis.assign(n + 1, 0);
    inStack.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if (dfs(i, graph)) {
                vector<int> cycle;
                cycle.push_back(cycle_start);
                for (int v = cycle_end; v != cycle_start; v = parent[v]) {
                    cycle.push_back(v);
                }
                cycle.push_back(cycle_start); // complete the cycle
                reverse(cycle.begin(), cycle.end());

                cout << cycle.size() << '\n';
                for (int city : cycle) cout << city << " ";
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
