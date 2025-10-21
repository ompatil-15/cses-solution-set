// Author: cyberman
// Algorithm: Prim's Algorithm (Minimum Spanning Tree)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, wt;
        cin >> a >> b >> wt;
        graph[a].push_back(make_pair(b, wt));
        graph[b].push_back(make_pair(a, wt));
    }

    vector<bool> vis(n+1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    long long cost = 0;

    while (!pq.empty()) {
        auto [c, node] = pq.top();
        pq.pop();
        if (vis[node]) continue;
        vis[node] = true;
        cost += c;
        for(auto [adjNode, adjCost] : graph[node]){
            if (!vis[adjNode]) pq.push({adjCost, adjNode});
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << cost << endl;

}