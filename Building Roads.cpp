    // Author: cyberman
	// Algorithm: DFS, Union-Find

    #include <bits/stdc++.h>
    using namespace std;

	typedef long long ll;

	// Union-Find

	int findParent(ll c, vector<ll> &parent) {
		if (parent[c] != c) parent[c] = findParent(parent[c], parent);
		return parent[c];
	} 

	void unionNodes(ll c1, ll c2 , vector<ll> &parent, vector<ll> &rank) {
		ll p1 = findParent(c1, parent);
		ll p2 = findParent(c2, parent);
		if (p1 != p2) {
			if (rank[p1] > rank[p2]) {
				parent[p2] = p1;
			} else if (rank[p2] > rank[p1]) {
				parent[p1] = p2;
			} else {
				parent[p2] = p1;
				rank[p1]++;
			}
		}
	}

	int main() {
		ll nc, nr;
		cin >> nc >> nr;
		vector<ll> parent(nc+1);
		vector<ll> rank(nc+1, 0);

		for (int i = 1; i <= nc; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < nr; i++) {
			ll c1, c2;
			cin >> c1 >> c2;
			unionNodes(c1, c2, parent, rank);
		}

		set<ll> uniques;
		for (ll i = 1; i <= nc; i++) {
			uniques.insert(findParent(i, parent));
		}

		ll ans = uniques.size() - 1;
		cout << ans << endl;

		vector<ll> parents(uniques.begin(), uniques.end());
		for (int i = 1; i < parents.size(); i++) {
			cout << parents[0] << ' ' << parents[i] << endl;
		}
	}	

	// // DFS

	// void dfs(ll c, unordered_map<ll, vector<ll>> &roads, vector<bool> &vis, ll nc, ll nr) {
	// 	if (c < 1 || c > nc || vis[c]) return;
	// 	vis[c] = true;
	// 	for (ll it : roads[c]) {
	// 		dfs(it, roads, vis, nc, nr);
	// 	}
	// }

	// int main() {
	// 	ll nc, nr, disjoints = 0;
	// 	cin >> nc >> nr;
	// 	unordered_map<ll, vector<ll>> roads;
	// 	vector<bool> vis(nc, false);
	// 	vector<ll> unique;
		
	// 	for (int i = 0; i < nr; i++) {
	// 		ll c1, c2;
	// 		cin >> c1 >> c2;
	// 		roads[c1].push_back(c2);
	// 		roads[c2].push_back(c1);
	// 	}

	// 	for (int i = 1; i <= nc; i++) {
	// 		if (!vis[i]){
	// 			disjoints++;
	// 			unique.push_back(i);
	// 			dfs(i, roads, vis, nc, nr);
	// 		}
	// 	}
	// 	cout << disjoints-1 << endl;
	// 	if (disjoints > 1) {
	// 		for (int i = 1; i < unique.size(); i++) {
	// 			cout << unique[0] << " " << unique[i] << endl;
	// 		}
	// 	}
	// 	return 0;
	// } 