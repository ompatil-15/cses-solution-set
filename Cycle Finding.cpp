// Author: cyberman
// Algorithm: Bellman Ford

// You get the node which is affected by the negative cycle
// Trace back its parent n time that is the number of nodes
// By doing this you ensure that you get in the negative cycle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;	

int main() {
	ll n, m;
	cin >> n >> m;
	vector<array<ll,3>> graph(m);
	// We initialize all distances to 0 instead of LLONG_MAX
	// This makes sure that we can relax even those cycles that are unreacheable from source 1
	// It's like having a source node to every node
	vector<ll> dist(n+1, 0); 
	vector<ll> parent(n+1, -1); // made mistake of assigning parent as source for every node
	dist[1] = 0; 
	ll node = -1;

	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[i] = {a,b,c};
	}

	for (int i = 0; i < 2*n; i++) {
		for (auto edge : graph){
			ll u = edge[0];
			ll v = edge[1];
			ll w = edge[2];

			if (dist[u] != LLONG_MAX && dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				parent[v] = u;
				if (i == n-1) {
					node = v;
				}
			}
		}
	}

	if (node == -1) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	for (int i = 0; i < n; i++) {
		if (node == -1) break;
		node = parent[node];
	}

	unordered_set<ll> nodes;
	vector<ll> ans;
	while (nodes.find(node) == nodes.end()) {
		if (node == -1) break;
		ans.push_back(node);
		nodes.insert(node);
		node = parent[node];
	}
	ans.push_back(node);
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;	
	return 0;
}