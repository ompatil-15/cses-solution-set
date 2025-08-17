// Author: cyberman
// Algorithm: DFS with parent memoization

// Approach

// 1. We do normal DFS traversal with parent vector 
// 2. But since we want to find the max path size
// 3. Always updating the parent can lead to stale value for the max path
// 4. We only update the parent on the max path length
// 5. We also memoize the path for optimization
// 6. In the longest path DFS the parent logic is opposite as we need to forward pass
// 7. Have a bottom-up approach, with base cases, don't try to propagate the path length 
// 8. parent array bookeeping matter depending on shortest / longest path
// 9. in bfs u->v parent[v] = u as v is the shortest path till now
// 10. in this case we are coming from n->v so parent[u] = v, if we are at u go to v for max path
// 11. important concept: parent bookeeping for shortest/longest

#include <bits/stdc++.h>
using namespace std;

int dfs(int n, vector<vector<int>> &graph, vector<int> &parent, vector<int> &dist, int last) {

    if (dist[n] != -1) return dist[n];
    if (n == last) return 1;
    
    int best = -1e9;

    for (int adj : graph[n]) {
        int path = dfs(adj, graph, parent, dist, last);
        if (path != -1e9 && path + 1 > best) {
            best = path + 1;
            parent[n] = adj;
        }
    }

    return dist[n] = best;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> parent(n + 1, -1);
    vector<int> dist(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int longest = dfs(1, graph, parent, dist, n);

    if (longest < 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } else {
        cout << longest << endl;
        vector<int> path;
        for (int i = 1; i != n; i = parent[i]) {
            path.push_back(i);
        }
        path.push_back(n);
        for (int node : path) {
            cout << node << " ";
        }
    }

    return 0;
}
