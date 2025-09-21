
// Author: cyberman

const long long MOD = 1e9 + 7;
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

ll dfs(int n, vector<vector<int>> &graph, int last, vector<int> &dp) {
    if (dp[n] != -1) return dp[n];
    if (n == last) return 1;

    ll total = 0;
    for (int adj : graph[n]) {
        ll ways = dfs(adj, graph, last, dp) % MOD;
        total = (total + ways) % MOD;
    }

    return dp[n] = total % MOD;
}

int main () {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> dp(n+1, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    ll total = dfs(1, graph, n, dp) % MOD;

    cout << total << endl;
    
    return 0;
}