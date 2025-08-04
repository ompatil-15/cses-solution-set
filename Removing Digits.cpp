// Author: cyberman
// Algorithm: DP

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Tabulation
int main () {
    ll n; 
    cin >> n;

    vector<ll> dp(n+1, LLONG_MAX);
    dp[0] = 0;

    for (ll i = 1; i <= n; i++) {

        ll temp = i;
        while (temp) {
            ll digit = temp % 10;
            temp /= 10;
            if (i-digit >= 0 && digit != 0) {
                dp[i] = min(dp[i], 1 + dp[i-digit]);
            }
        }
    }
    cout << dp[n] << endl;
}


// Memoization
// ll f(ll n, vector<ll> &dp) {
//     if (n == 0) return 0;
//     if (dp[n] != -1) return dp[n];
//     ll steps = LLONG_MAX;
//     ll temp = n;
//     while (temp) {
//         ll digit = temp % 10;
//         if (digit != 0) steps = min(steps, 1 + f(n-digit, dp));
//         temp /= 10;
//     }
//     return dp[n] = steps;
// }

// int main() {
//    ll n;
//    cin >> n;
//    vector<ll> dp(n+1, -1);

//    ll ans = f(n, dp); 
//    cout << ans << endl;
// }