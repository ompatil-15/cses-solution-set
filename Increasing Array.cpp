// Author: cyberman

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n, ans = 0;
	cin >> n;
	vector<long long int> arr(n);

	for (int i = 0; i < n; i++)	{
		long long int val;
		cin >> val;
		arr[i] = val;
	}

	for (int i = 1; i < n; i++)	{
		ans += max(0LL, arr[i - 1] - arr[i]);
		arr[i] = max(arr[i], arr[i-1]);
	}

	cout << ans << endl;
}