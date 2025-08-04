// Author: cyberman
// Algorithm: DP

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    ll n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char> (n));
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == '*') {
        cout << 0 << endl; 
        return 0;
    }
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0; 
            } else {
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << (dp[n-1][n-1]) % MOD << endl;
}

// ll f(ll r, ll c, vector<vector<char>> &grid, ll n, vector<vector<ll>> &dp) {
//     if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == '*') return 0;
//     if (r == n-1 && c == n-1) return 1;

//     if (dp[r][c] != -1) return dp[r][c];
    
//     ll right = f(r, c+1, grid, n, dp) % MOD;
//     ll down = f(r+1, c, grid, n, dp) % MOD;

//     return dp[r][c] = (right + down) % MOD;
// }

// int main () {
//     ll n;
//     cin >> n;
//     vector<vector<char>> grid(n, vector<char> (n));
//     vector<vector<ll>> dp(n, vector<ll>(n, -1));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             char cell;
//             cin >> cell;
//             grid[i][j] = cell;
//         }
//     }

//     ll ans  = f(0, 0, grid, n, dp) % MOD;
//     cout << ans << endl;
// }