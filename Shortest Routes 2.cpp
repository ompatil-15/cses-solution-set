// Author: cyberman
// Algorithm: Floyd Warshall

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;	

int main() {
	ll n, m, q, a, b;
	cin >> n >> m >> q;

	vector< vector<ll>> graph(n+1, vector<ll>(n+1, LLONG_MAX)); 

	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
		graph[b][a] = min(graph[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] != LLONG_MAX && graph[k][j] != LLONG_MAX && (graph[i][k] + graph[k][j] < graph[i][j])) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		ll ans = (graph[a][b] == LLONG_MAX) ? -1 : graph[a][b];
		cout << ans << endl;
	}

	return 0;
}
