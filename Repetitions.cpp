// Author: cyberman
	
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
  cin >> s;
  long long ans = 0;

  for (int i = 0; i < s.size(); i++) {
    long long count = 1;
    while (i < s.size() - 1  && s[i] == s[i+1]) {
      count++;
      i++;
    }
    ans = max(ans, count);
  }

  cout << ans << endl;
	return 0;
}	