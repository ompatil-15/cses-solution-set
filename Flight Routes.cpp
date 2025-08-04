// Author: cyberman
// Algorithm: Dijkstra with distance stored as max heap

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;	

int main() {
	
	ll n, m, k;
	cin >> n >> m >> k;
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	unordered_map<ll, vector<pair<ll, ll>>> graph;
	vector<priority_queue<ll>> dist(n+1);

	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}

	dist[1].push(0);
	pq.push({0, 1});

	while(!pq.empty()) {
		auto [d, city] = pq.top();
		pq.pop();

		if (d > dist[city].top()) continue;

		for (auto &it : graph[city]) {
			auto [adj, cost] = it;
			ll newD = d + cost;
			 if (dist[adj].size() < k) {
				dist[adj].push(newD);
				pq.push({newD, adj});
			} else if (newD < dist[adj].top()) {
				dist[adj].pop();
				dist[adj].push(newD);
				pq.push({newD, adj});
			}
		}
	}	

	vector<ll> ans;
	
	while(dist[n].size()) {
		ans.push_back(dist[n].top());
		dist[n].pop();
	}

	reverse(ans.begin(), ans.end());
	for (ll d : ans) {
		cout << d << " ";
	}
	cout << endl;
	return 0;
}