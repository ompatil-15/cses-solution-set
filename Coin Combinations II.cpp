// Author: cyberman
// Algorithm: DP

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    ll n, sum;
    cin >> n >> sum;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<ll> dp(sum+1, 0);
    dp[0] = 1;

    for (ll i = 0; i < n; i++) {
        for (ll j = coins[i]; j <= sum; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
        }
    }

    cout << dp[sum] << endl;

}

// ll f(ll ind, vector<ll> &coins, ll sum, ll &target, vector<vector<ll>> &dp) {
// 	if (ind >= coins.size()) return 0;
// 	if (sum == target) return 1;

// 	if (dp[ind][sum] != -1) return dp[ind][sum];

// 	ll pick = 0, notPick = 0;
// 	if (sum + coins[ind] <= target) pick = f(ind, coins, sum+coins[ind], target, dp) % MOD;
// 	notPick = f(ind+1, coins, sum, target, dp) % MOD;

// 	return dp[ind][sum] = (pick + notPick) % MOD;
// }


// int main() {

// 	ll n, sum;
// 	cin >> n >> sum;
// 	vector<ll> coins(n);

// 	for (int i = 0; i < n; i++) {
// 		cin >> coins[i];
// 	}

// 	vector<vector<ll>> dp(n, vector<ll>(sum+1, -1));
// 	ll ans = f(0, coins, 0, sum, dp) % MOD;
// 	cout << ans << endl;
// 	return 0;
// }