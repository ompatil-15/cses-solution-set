// Author: cyberman
// Algorithm: DP

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 1D DP
int main() {
    ll n, x; 
    cin >> n >> x;
    vector<ll> prices(n);
    vector<ll> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<ll> dp(x+1, 0);

        for (int i = 0; i < n; i++) {
            for(int j = x; j >= prices[i]; j--) {
                dp[j] = max(dp[j], dp[j-prices[i]] + pages[i]);
            }
        }

    cout << dp[x] << endl;
}
// 2D DP
// int main() {
//     ll n, x; 
//     cin >> n >> x;
//     vector<ll> prices(n);
//     vector<ll> pages(n);
//     for (int i = 0; i < n; i++) {
//         cin >> prices[i];
//     }
    
//     for (int i = 0; i < n; i++) {
//         cin >> pages[i];
//     }

//     vector<vector<ll>> dp(n+1, vector<ll> (x+1, 0));

//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= x; j++) {
//             dp[i][j] = dp[i-1][j];
//             if (j >= prices[i-1]) dp[i][j] = max(dp[i][j], pages[i-1] + dp[i-1][j-prices[i-1]]);
//         }
//     }
//     cout << dp[n][x] << endl;
// }

// Memoization
// ll f(ll ind, ll x, vector<ll> &prices, vector<ll> &pages, vector<vector<ll>> &dp) {
//     if (ind >= prices.size() || x <= 0) return 0;

//     if (dp[ind][x] != -1) return dp[ind][x];
    
//     ll pick = 0, notPick = 0;

//     if (prices[ind] <= x) pick = pages[ind] + f(ind+1, x-prices[ind], prices, pages, dp);
//     notPick = f(ind+1, x, prices, pages, dp);

//     return dp[ind][x] = max(pick, notPick);

// }   

// int main () {
//     ll n, x;
//     cin >> n >> x;

//     vector<ll> prices(n);
//     vector<ll> pages(n);
    
//     vector<vector<ll>> dp(n, vector<ll> (x+1, -1));
    
//     for (int i = 0; i < n; i++) {
//         cin >> prices[i];
//     }
//     for (int i = 0; i < n; i++) {
//         cin >> pages[i];
//     }

//     ll ans = f(0, x, prices, pages, dp);
//     cout << ans << endl;
// }