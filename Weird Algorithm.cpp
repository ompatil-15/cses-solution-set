// Author: cyberman
	
#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	
	if (n <= 0) cout << -1 << endl;
  
	while (n > 1) {
		cout << n << " ";
		if (n%2 == 0) n /= 2;
	  else n = 3*n + 1;
	}

	cout << n << endl;
	return 0;
}	