// Author: cyberman
	
#include <iostream>
using namespace std;

int main() {
	long long t;
  long long sum = 0;
  cin >> t;
  long long expectedSum = (t*(t+1))/2;

  while (t > 1) {
    long long n;
    cin >> n;
    sum += n;
    t--;
  }
  
  cout << expectedSum - sum << endl;	
	return 0;
}	