    // Author: cyberman

    #include <bits/stdc++.h>
    using namespace std;

	typedef long long ll;

	int main() {
		int n, target;
		cin >> n >> target;

		vector<ll> dp(target+1, LLONG_MAX);
		vector<ll> coins;
		dp[0] = 0;

		for (int i = 0; i < n; i++) {
			ll coin;
			cin >> coin;
			coins.push_back(coin);
		}

		for (int i = 1; i <= target; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (i-coins[j] >= 0 && dp[i - coins[j]] != LLONG_MAX) dp[i] = min(dp[i], dp[i-coins[j]]+1);
			}
		}
		int ans = dp[target];
		if (ans == LLONG_MAX) ans = -1;
		cout << ans << endl;
	}