// Author: cyberman
// Algorithm: Binary lifting for functional graphs (all nodes have outdegree 1)

// Notes
// Functional graph: tree with a cycle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int kLog = 32;
    // vector<vector<ll>> query(n+1, vector<ll> (kLog, -1));
    static int query[200000][32]; 

    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        query[i][0] = x;
    }

    for (ll s = 1; s < kLog; s++) {
        for (ll planet = 1; planet <= n; planet++) {
            query[planet][s] = query[query[planet][s-1]][s-1];
        }
    }

    for (ll i = 0; i < q; i++) {
        ll start, steps;
        cin >> start >> steps;

        ll curr = start;
        for (ll p = 0; p < kLog; p++) {
            if ((steps >> p) & 1) {
                if (curr == -1) break;
                curr = query[curr][p];
            }
        }
        cout << curr << "\n";
    }
}
