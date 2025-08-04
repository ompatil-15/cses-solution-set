    // Author: cyberman
	// Bipartite Graph
	// Algorithm: BFS

    #include <bits/stdc++.h>
    using namespace std;

	typedef long long ll;

	int main() {
		ll n, m;
		cin >> n >> m;
		unordered_map<ll, vector<ll>> graph;
		vector<ll> team(n+1, 0);
		queue<ll> q;
		
		for (int i = 0; i < m; i++) {
			ll a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (team[i] == 0) {
				q.push(i);
				team[i] = 1;

				while(!q.empty()) {
					ll pupil = q.front();
					q.pop();

					for (ll neighbour : graph[pupil]) {
						if (team[neighbour] == 0) {
							team[neighbour] = 3 - team[pupil];
							q.push(neighbour);
						} else if (team[neighbour] == team[pupil]) {
							cout << "IMPOSSIBLE" << endl;
							return 0;
						}
					}
				}
			}
		}

		for (int i = 1; i < team.size(); i++) {
			cout << team[i] << " ";
		}
		cout << endl;
		return 0;
	}