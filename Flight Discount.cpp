// Author: cyberman
// Algorithm: State Dijkstra
// Maintain the state of ticket availabiltiy 
// in the priority queue and push it to find 
// the shortest distance considering usage of 
// ticket once

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;	

int main() {
	ll n, m;
	cin >> n >> m;
	unordered_map<ll, vector<pair<ll,ll>>> graph;
	priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
	vector<vector<ll>> dist(2, vector<ll>(n+1, LLONG_MAX));
	dist[0][1] = 0;
	dist[1][1] = 0;
	pq.push({0, 1, 0}); // {distance, node, ticket_used}

	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}

	while (!pq.empty()) {
		auto [c, u, t] = pq.top();
		pq.pop();

		if (dist[t][u] < c) continue;

		for (auto &it : graph[u]) {
			ll v = it.first;
			ll cost = it.second;
			if (t == 0) {
				if (dist[0][v] > c + cost) {
					dist[0][v] = c + cost;
					pq.push({dist[0][v], v, 0});
				}
				if (dist[1][v] > c + cost/2) {
					dist[1][v] = c + cost/2;
					pq.push({dist[1][v], v, 1});
				}
			} else {
				if (dist[1][v] > c + cost) {
					dist[1][v] = c + cost;
					pq.push({dist[1][v], v, 1});
				}
			}
		}
	}

	cout << min(dist[0][n], dist[1][n]) << endl;

	return 0;
}