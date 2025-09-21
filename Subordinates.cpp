#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>> &graph, vector<int> &subord) {
    int total = 0;
    for (int adj : graph[node]) {
        total += dfs(adj, graph, subord);
    }
    subord[node] = total;
    return total + 1;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> graph(n+1);
    vector<int> subord(n+1, 0);

    for (int i = 2; i <= n; i++) {
        int node;
        cin >> node;
        graph[node].push_back(i);
    }

    dfs(1, graph, subord);

    for (int i = 1; i <= n; i++) {
        cout << subord[i] << " ";
    }

    return 0;
}