// Author: cyberman
// Algorithm: DSU 

// Notes
//
// Dynamic graph -> can't use dfs, bfs optimally
// Use Disjoint Set Union (DSU)

#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent); 
    }
    return parent[x];
}

void merge(int x, int y, vector<int> &parent, vector<int> &size) {
    int parentX = find(x, parent);
    int parentY = find(y, parent);

    if (parentX == parentY) return;

    if (size[parentX] > size[parentY]){
        parent[parentY] = parentX;
        size[parentX] += size[parentY];
    } else {
        parent[parentX] = parentY;
        size[parentY] += size[parentX];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int components = n;
    int maxSize = 1;
    vector<int> size(n+1, 1);
    vector<int> parent(n+1, -1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int parentA = find(a, parent);
        int parentB = find(b, parent);
        if (parentA != parentB) {
            merge(a, b, parent, size);
            components--;
        }
        int root = find(a, parent);
        maxSize = max(maxSize, size[root]);
        cout << components << " " << maxSize << "\n";
    }
}