    // Author: cyberman
	// Algorithm: BFS

    #include <bits/stdc++.h>
    using namespace std;

	typedef long long ll;	

	int main() {
		ll n, m, sr, sc, er, ec;
		bool flag = false;
		vector<int> dr = {-1, 0, 1, 0};
		vector<int> dc = {0, 1, 0, -1};
		vector<char> dir = {'U', 'R', 'D', 'L'};

		cin >> n >> m;
		vector<vector<char>> labyrinth(n, vector<char> (m));

		for (ll i = 0; i < n; i++) {
			for(ll j = 0; j < m; j++) {
				char tile;
				cin >> tile;
				if (tile == 'A') {
					sr = i; 
					sc = j;
				}
				if (tile == 'B') {
					er = i; 
					ec = j;
				}
				labyrinth[i][j] = tile;
			}
		}

		queue<pair<int, int>> q;
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m, {-1, -1}));
		q.push({sr, sc});
		vis[sr][sc] = true;

		while (!q.empty()) {
			auto it = q.front();
			q.pop();

			int r = it.first;
			int c = it.second;

			if (r == er && c == ec) {
				flag = true;
				break;
			}

			for (ll i = 0; i < 4; i++) {
				int newR = r+dr[i];
				int newC = c+dc[i];

				if (newR >= 0 && newC >= 0 && newR < n && newC < m && !vis[newR][newC] && labyrinth[newR][newC] != '#') {
					q.push({newR, newC});
					vis[newR][newC] = true;
					parent[newR][newC] = {r, c};
				}
			}
		}

		if (!flag) cout << "NO" << endl;
		if (flag) {
			cout << "YES" << endl;
			string path = "";
			ll r = er, c = ec;
			while (make_pair(r, c) != make_pair(sr, sc)) {
				auto [pr, pc] = parent[r][c];
				for (int i = 0; i < 4; i++) {
					if (pr+dr[i] == r && pc+dc[i] == c) {
						path += dir[i];
						break;
					}
				} 	
				r = pr;
				c = pc;
			}
			reverse(path.begin(), path.end());
			cout << path.size() << endl;
			cout << path << endl;
		}
		return 0;
	}