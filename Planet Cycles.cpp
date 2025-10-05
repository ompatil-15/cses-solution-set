// Author: cyberman
// Algorithm: DFS

// Approach
//
// Traverse with DFS, count the dist from each starting node
// If your come across a visited node, cycle is detected
// Calculate the cycle lenght using dist[node] - dist[cycleStart] + 1
// All the nodes in the cycle will have cycleLenth as answer
// All the nodes in the tree part, we will keep incrementing the value of their parent

#include <bits/stdc++.h>
using namespace std;

static int cycleStart = -1;
static int cycleLength = -1;

void dfs(int node, vector<int> &next, vector<int> &dist, vector<int> &dp, vector<bool> &visited, int d) {
    if (visited[node]) return;

    visited[node] = true;
    dist[node] = d;

    dfs(next[node], next, dist, dp, visited, d+1);

    if (dp[next[node]] == 0) {
        cycleStart = next[node];
        cycleLength = dist[node] - dist[next[node]] + 1;
    }

    if (cycleStart != -1) {
        dp[node] = cycleLength;
        if (node == cycleStart) cycleStart = -1;
    } else {
        dp[node] = dp[next[node]] + 1;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> next(n+1, -1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        next[i] = x;
    }

    vector<int> dist(n+1, 0);
    vector<int> dp(n+1, 0);
    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, next, dist, dp, visited, 0);
        }
    }

    for (int i = 1; i <=n; i++) {
        cout << dp[i] << "\n";
    }
}