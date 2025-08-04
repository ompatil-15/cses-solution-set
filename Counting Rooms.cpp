    // Author: cyberman
	// Algorithm: DFS

    #include <bits/stdc++.h>
    using namespace std;

	typedef long long ll;

	void dfs(int r, int c, vector<vector<char>> &building) {
		if (r < 0 || c < 0 || r >= building.size() || c >= building[0].size() || building[r][c] == '#') return;
		building[r][c] = '#';
		vector<int> dr = {-1, 0, +1, 0};
		vector<int> dc = {0, +1, 0, -1};

		for (int i = 0; i < 4; i++) {
			dfs(r+dr[i], c+dc[i], building);
		}
	}

	int main() {
		ll n, m;
		cin >> n >> m;
		int ans = 0;
		vector<vector<char>> building(n, vector<char> (m));

		for (int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> building[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if (building[i][j] == '.') {
					ans++;
					dfs(i, j, building);
				}
			}
		}

		cout << ans << endl;		
	}