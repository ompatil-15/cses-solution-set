// Author: cyberman
// Algorithm: dijkstras

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Step 1: Calculate the dist[x] using dijkstra's
// Step 2: Use the dist[x] to process the ways, min_path, max_path
// Iterate the nodes in the increasing order of dist[x]
// u -> v = w falls on the shortest path if dist[u] == dist[v] + wt 
// ways[v] += ways[u] given dist[u] < dist[v]
// min_path/max_path is calculated similarly

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> graph(n+1);

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    vector<ll> dist(n+1, LLONG_MAX);
    dist[1] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push(make_pair(0, 1));

    while (!q.empty()) {
        auto [d, node] = q.top();
        q.pop();
        if (d > dist[node]) continue;
        for(auto [adj, wt] : graph[node]) {
            if (d+wt < dist[adj]) {
                dist[adj] = d+wt;
                q.push(make_pair(d+wt, adj));
            }
        }
    }

    const ll MOD = 1e9+7;

    vector<ll> ways(n+1, 0), min_path(n+1, LLONG_MAX), max_path(n+1, -LLONG_MAX);
    ways[1] = 1;
    min_path[1] = 0;
    max_path[1] = 0;

    vector<ll> order(n);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(), [&](ll a, ll b) {
        return dist[a] < dist[b];
    });

    for (ll u : order) {
        if (dist[u] == LLONG_MAX) continue;
        for (auto [v, wt] : graph[u]) {
            if (dist[v] == dist[u] + wt) {
                ways[v] = (ways[u] + ways[v]) % MOD;
                min_path[v] = min(min_path[v], min_path[u]+1);
                max_path[v] = max(max_path[v], max_path[u]+1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << min_path[n] << " " << max_path[n] << endl;
}   