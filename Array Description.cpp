// Author: cyberman
// Algorithm: DP

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

// Tabulation
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<vector<ll>> dp(n+1, vector<ll>(m+2, 0));
  if (arr[0] == 0) {
      for (int i = 1; i <= m; i++) {
        dp[0][i] = 1;
      }
  } else {
    dp[0][arr[0]] = 1; 
  }

  for (int i = 1; i < n; i++) {
    for (int val = 1; val <= m; val++) {
      if (arr[i] == 0 || arr[i] == val) {
        dp[i][val] = ((dp[i-1][val] + dp[i-1][val-1]) % MOD + dp[i-1][val+1]) % MOD;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = (ans + dp[n-1][i]) % MOD;
  }

  cout << ans << endl;
} 

// Memoization
// ll f(ll ind, ll prev, ll m, vector<ll> &arr, vector<vector<ll>> &dp) {

//   if (ind >= arr.size()) return 1;

//   if (dp[ind][prev] != -1) return dp[ind][prev];

//   ll count = 0;

//   if (arr[ind] == 0) {
//     for (int i = 1; i <= m; i++) {
//       if (abs(i-prev) <= 1) {
//         count = (count + f(ind+1, i, m, arr, dp)) % MOD;
//       }
//     }
//   } else {
//     if (abs(arr[ind] - prev) <= 1) {
//       count = (count + f(ind+1, arr[ind], m, arr, dp)) % MOD;
//     }
//   }

//   return dp[ind][prev] = count;

// }

// int main() {

//   ll n, m;
//   cin >> n >> m;
//   vector<ll> arr(n);
//   vector<vector<ll>> dp(n+1, vector<ll>(m+1, -1));

//   for (ll i = 0; i < n; i++) {
//     ll num;
//     cin >> num;
//     arr[i] = num;
//   }

//   ll ans = 0;

//   if (arr[0] == 0) {
//     for(int i = 1; i <= m; i++) {
//       ans = (ans + f(1, i, m, arr, dp))  % MOD;
//     }
//   } else {
//     ans = f(1, arr[0], m, arr, dp) % MOD;
//   }

//   cout << ans << endl;
// }