    // Author: cyberman

    #include <bits/stdc++.h>
    using namespace std;

	int main() {
		int n;
		cin >> n;

		vector<long long> dp(n+1, 0);
		dp[0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 6; j++) {
				if (i-j >= 0) dp[i] += dp[i-j] % 1000000007;
			}
		}
		cout << dp[n] % 1000000007 << endl;
	}

	// // Recursion with memoization

	// long long f(long long n, vector<long long> &dp) {
	// 	if (n == 0) return 1;
	// 	if (n < 0) return 0;
	// 	if (dp[n] != -1) return dp[n];

	// 	long long count = 0;

	// 	for (int i = 1; i <=6; i++) {
	// 		count += f(n-i, dp);
	// 	}
	// 	return dp[n] = count;
	// }	

    // int main() {
    //     long long n;
	// 	cin >> n;
	// 	vector<long long> dp(n+1, -1);
	// 	long long ans = f(n, dp) % (1000000007);
	// 	cout << ans << endl;
    // }