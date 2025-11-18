// Author: cyberman
// Algorithm: Kosaraju with component labelling

// Approach
//
// First we start a dfs for each unvisited node
// We will have two SCC components that might be connected by one directional edge
// Thus, if we are able to process the node in the same order on the reversed graph
// The edge that took us to the adj SCC will be reverted and we will no longer will be able to traverse 
// Thus we will be trapped in a unique SCC
// We will label all the nodes while the second dfs
// Additionally, to contract the SCC we can iterate through all the edges
// if they belong to different components then create an edge betweeen those components

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, stack<int> &st, vector<bool> &vis, bool flag, int k, vector<int> &kingdom) {
    if (vis[node]) return;
    vis[node] = true;
    if (flag) kingdom[node] = k;
    for (int adj : graph[node]) {
        dfs(adj, graph, st, vis, flag, k, kingdom);
    }
    st.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<vector<int>> reverseGraph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }

    stack<int> st;
    vector<bool> vis(n+1, false);
    vector<int> kingdom(n+1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, graph, st, vis, false, -1, kingdom);
        }
    }

    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }

    int k = 1;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            dfs(node, reverseGraph, st, vis, true, k, kingdom);
            k++;
        }
    }

    cout << k-1 << "\n";
    
    for (int i = 1; i <=n; i++) {
        cout << kingdom[i] << " ";
    }
    cout << "\n";
}