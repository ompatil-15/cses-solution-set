    // Author: cyberman
	// Algorithm: Dijkstra

    #include <bits/stdc++.h>
    using namespace std;

	typedef long long ll;	

	int main() {
		ll n, m;
		cin >> n >> m;

		// pre-allocation results in faster speeds, 
		// as allocating memory at run time leads to 
		// copying all existing memory to new memory blocks 
		// and deallocating the old memory which is resource expensive
		// Learning: Always pre-allocate memory if possible
		vector< vector<pair<ll, ll>>> graph(n+1); 
		
		vector<ll> dist(n+1, LLONG_MAX);
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
		dist[1] = 0;
		pq.push({0, 1});

		for (int i = 0; i < m; i++) {
			ll a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, c)); // one-way flight
		}

		while (!pq.empty()) {
			auto [cityDistance, city] = pq.top();
			pq.pop();

			if (cityDistance > dist[city]) continue;

			for (auto it2 : graph[city]) {
				ll adj = it2.first;
				ll d = it2.second;
				ll newD = cityDistance + d;
				if (newD < dist[adj]) {
					dist[adj] = newD;
					pq.push(make_pair(newD, adj));
				}
			}
		}

		for (int i = 1; i < dist.size(); i++) {
			cout << dist[i] << " ";
		}
		cout << endl;

		return 0;
	}