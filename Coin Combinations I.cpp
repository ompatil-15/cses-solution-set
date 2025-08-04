// Author: cyberman
// Algorithm: 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

ll f(vector<ll> &coins, ll sum, ll &target, vector<ll> &dp) {
	if (sum > target) return 0;
	if (sum == target) return 1;

	if (dp[sum] != -1) return dp[sum];

	ll comb = 0;
	for (int i = 0; i < coins.size(); i++) {
		comb += f(coins, sum+coins[i], target, dp) % MOD;
	}
	return dp[sum] = comb % MOD;
}


int main() {

	ll n, sum;
	cin >> n >> sum;
	vector<ll> coins(n);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	// Memoization
	// vector<ll> dp(sum+1, -1);
	// ll ans = f(coins, 0, sum, dp) % MOD;
	// cout << ans << endl;

	// Tabulation
	vector<ll> dp(sum+1, 0);
	dp[0] = 1;

	for (int i = 1; i <= sum; i++) {
		for (int j = 0; j < n; j++) {
			ll coin = coins[j];
			if (i - coin >= 0) {
				dp[i] += (dp[i-coin] % MOD);
				dp[i] = dp[i] % MOD;
			}
		}
	}

	cout << dp[sum] << endl;

	return 0;
}