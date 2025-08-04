// Author: cyberman
// Algorithm: Multisource BFS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll r, c;
};

vector<ll> dr = {-1, 0, 1, 0};
vector<ll> dc = {0, 1, 0, -1};
vector<char> dir = {'U', 'R', 'D', 'L'};

bool isValid(ll r, ll c, vector<vector<char>>& mat) {
    return r >= 0 && r < mat.size() && c >= 0 && c < mat[0].size() && mat[r][c] == '.';
}

bool isBoundary(ll r, ll c, ll n, ll m) {
    return r == 0 || r == n - 1 || c == 0 || c == m - 1;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<ll>> monsterTime(n, vector<ll>(m, LLONG_MAX));
    vector<vector<ll>> playerTime(n, vector<ll>(m, LLONG_MAX));
    vector<vector<pair<ll, ll>>> parent(n, vector<pair<ll, ll>>(m, {-1, -1}));
    queue<Point> monsterQueue, playerQueue;

    pair<ll, ll> start;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'M') {
                monsterQueue.push({i, j});
                monsterTime[i][j] = 0;
            } else if (mat[i][j] == 'A') {
                start = {i, j};
                playerQueue.push({i, j});
                playerTime[i][j] = 0;
            }
        }
    }

	if (isBoundary(start.first, start.second, n, m)) {
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}

    // Step 1: BFS for monster influence
    while (!monsterQueue.empty()) {
        auto [r, c] = monsterQueue.front();
        monsterQueue.pop();
        for (ll i = 0; i < 4; i++) {
            ll nr = r + dr[i], nc = c + dc[i];
            if (isValid(nr, nc, mat) && monsterTime[nr][nc] == LLONG_MAX) {
                monsterTime[nr][nc] = monsterTime[r][c] + 1;
                monsterQueue.push({nr, nc});
            }
        }
    }

    // Step 2: BFS for player escape
    pair<ll, ll> end = {-1, -1};
    bool escaped = false;
    while (!playerQueue.empty() && !escaped) {
        auto [r, c] = playerQueue.front();
        playerQueue.pop();

        for (ll i = 0; i < 4; i++) {
            ll nr = r + dr[i], nc = c + dc[i];
            if (isValid(nr, nc, mat) && playerTime[nr][nc] == LLONG_MAX) {
                if (playerTime[r][c] + 1 < monsterTime[nr][nc]) {
                    playerTime[nr][nc] = playerTime[r][c] + 1;
                    parent[nr][nc] = {r, c};
                    if (isBoundary(nr, nc, n, m)) {
                        escaped = true;
                        end = {nr, nc};
                        break;
                    }
                    playerQueue.push({nr, nc});
                }
            }
        }
    }

    if (escaped) {
        cout << "YES" << endl;
        string path;
        while (end != start) {
            auto [pr, pc] = parent[end.first][end.second];
            for (ll i = 0; i < 4; i++) {
                if (make_pair(pr + dr[i], pc + dc[i]) == end) {
                    path.push_back(dir[i]);
                }
            }
            end = {pr, pc};
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
