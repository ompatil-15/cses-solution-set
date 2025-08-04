// Author: cyberman
// Algorithm: Topological sort

// Approach

// 1. Keep a track of the indegree of all the nodes
// 2. Push all the nodes with 0 indegree into a queue and process by BFS
// 3. Decrease the indegree of all the adj nodes of the node at the top of the queue
// 4. Add the node to the ans vector and if any adj node indegree becomes 0 add that node to the queue
// 5. If the ans vector is the same lenght as the input vector that means it is possible to sort topologically
// 6. If the the length of the ans vector is less than input then not possible to sort topographically

#include <bits/stdc++.h>
using namespace std;

int main () {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<int> ans;
    vector<int> indegree(n+1, 0);
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        for (int adj : graph[i]) {
            indegree[adj]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int course  = q.front();
        q.pop();

        for (int adj : graph[course]) {
            indegree[adj]--;
            if (indegree[adj] == 0) {
                q.push(adj);
            }
        }
        ans.push_back(course);
    }

    if (static_cast<int>(ans.size()) == n) {
        for (int course : ans) {
            cout << course << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}