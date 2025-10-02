// Author: cyberman
// Algorithm: Binary lifting

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, q;
    cin >> n >> q;

    ll kLog = 50;
    vector<vector<ll>> query(n+1, vector<ll> (kLog, -1));

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
            if (1 << p & steps) {
                curr = query[curr][p];
            }
        }
        cout << curr << endl;
    }
}
