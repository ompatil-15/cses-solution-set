// Author: cyberman
// Algorithm: Binary Lifting

// Notes
//
// && is AND, & is Bitwise

#include <bits/stdc++.h>
using namespace std;

int logN(int n) {
  int logN = 0;
  while (n > 0) {
    logN++;
    n /= 2;
  }
  return logN;
}

int main() {
  int n, q;
  cin >> n >> q;

  int nLog = logN(n);

  vector<vector<int>> dp(n + 1, vector<int>(nLog + 1, -1));

  // root = 1, parent of 1 = -1
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    dp[i][0] = x;
  }

  for (int k = 1; k <= nLog; k++) {
    for (int i = 2; i <= n; i++) {
      if (dp[i][k - 1] != -1) {
        dp[i][k] = dp[dp[i][k - 1]][k - 1];
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int x, k;
    cin >> x >> k;
    int pow = 0;
    while (k > 0) {
      if (k & 1) {
        if (x != -1) {
          x = dp[x][pow];
        }
      }
      k = k >> 1;
      pow++;
    }
    cout << x << " ";
  }
}