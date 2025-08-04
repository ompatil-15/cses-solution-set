// Author: cyberman
// Algorithm: Bellman Ford

// Dijkstra fails when trying to maximise the distance,
// as it goes into infinite loop in presence of cycles
// We negate the weights and use bellman ford,
// to convert max problem to min
// after that we relax n time and propagate the positive cycle
// if dest is affected by positive cycle -1

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;	

int main() {
	ll n, m;
	cin >> n >> m;

	vector<array<ll, 3>> edges; 	
	vector<ll> dist(n+1, LLONG_MAX);
	dist[1] = 0;

	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		edges.push_back({a, b, -c});
	}
	

	for (int i = 1; i < n; i++) {
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != LLONG_MAX && dist[v] > dist[u] + wt) {
				dist[v] = dist[u] + wt;
			}
		}
	}

	vector<bool> cycle(n+1, false);

	for(int i = 0; i < n; i++) {
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != LLONG_MAX && dist[v] > dist[u] + wt) {
				dist[v] = dist[u] + wt;
				cycle[v] = true;
			}
			if (cycle[u]) cycle[v] = true;
		}
	}
	
	if (cycle[n]) {
		cout << -1 << endl;
	} else {
		cout << -dist[n] << endl;
	}

	return 0;
}