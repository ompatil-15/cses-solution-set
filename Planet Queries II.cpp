// Author: cyberman
// Algorithm: Binary lifting in functional graphs

// Approach
//
// Functional graph
// We can use binary lifting
// But our queries are of the form start, end
// We don't have dist as the input
// We need to leverage the binary lifting concept that takes start, dist 
// We can have a special point, calculate a->sp, b->sp
// Depending on the location of a,b we can infer about recheability of a from b
// The functional graph can contain either the tree part or the cycle part
// If b in on the way of a to special point the cycle start
// Then a->sp = x, b -> sp = y then a->b = x-y (prefix sum concept in graph)
// If we lift a by x-y and reach b then this case is satisfied
// Similarly the point b can be in the cycle, for which we start from cycle start
// Else the point b is can't be reached form a

#include <bits/stdc++.h>
using namespace std;

static int kLog = 20;
static int up[999999][20];

void dfs(int node, vector<int> &teleport, vector<int> &cycleDepth, vector<bool> &visited) {
    if (visited[node]) return;

    visited[node] = true;
    dfs(teleport[node], teleport, cycleDepth, visited);

    cycleDepth[node] = cycleDepth[teleport[node]] + 1;
    for (int i = 1; i < kLog; i++) {
        up[node][i] = up[up[node][i-1]][i-1];
    }
}

int jump(int a, int dist) {
    if (dist < 0) return -1;
    int node = a;
    for (int i = 0; i < kLog; i++) {
        if (dist >> i & 1) {
            node = up[node][i];
        }
    }
    return node;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> teleport(n+1, -1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        teleport[i] = x;
        up[i][0] = x;
    }

    vector<int> cycleDepth(n+1, 0);
    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, teleport, cycleDepth, visited);
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        int cycleStart = jump(a, cycleDepth[a]); // reach the cycle start
        
        if (jump(a, cycleDepth[a] - cycleDepth[b]) == b) { // b in on the way from a to cycle start
            cout << cycleDepth[a] - cycleDepth[b] << "\n";
        } else if (jump(cycleStart, cycleDepth[cycleStart] - cycleDepth[b]) == b) { // b is in cycle
            cout << cycleDepth[a] + cycleDepth[cycleStart] - cycleDepth[b] << "\n";
        } else { // b can't be reached from a
            cout << "-1" << "\n";
        }
    }
}