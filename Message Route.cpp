    // Author: cyberman
	// Algorithm: Dijkstra

    #include <bits/stdc++.h>
    using namespace std;

	typedef long long ll;

	int main() {
		ll n, m;
		cin >> n >> m;
		unordered_map<ll, vector<ll>> net;
		vector<ll> dist(n+1, LLONG_MAX);
		dist[1] = 1;
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
		pq.push({dist[1], 1});
		vector<ll> parent(n+1);

		for (int i = 1; i < parent.size(); i++) {
			parent[i] = i;
		}
 
		for (int i = 0; i < m; i++) {
			ll a, b;
			cin >> a >> b;
			net[a].push_back(b);
			net[b].push_back(a);
		}

		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			ll computer = it.second;
			ll d = it.first;
			for (ll adj : net[computer]) {
				if (dist[adj] > d+1) {
					dist[adj] = d+1;
					pq.push({d+1, adj});
					parent[adj] = computer;
				}
			}
		}

		if (dist[n] == LLONG_MAX) cout << "IMPOSSIBLE" << endl;
		else {
			cout << dist[n] << endl;
			ll c = n;
			vector<ll> path;
			while (c != 1) {
				path.push_back(c);
				c = parent[c];
			}
			path.push_back(c); 
			for (int i = path.size()-1; i >= 0; i--) {
				cout << path[i] << " ";
			}
		}
		return 0;
	}