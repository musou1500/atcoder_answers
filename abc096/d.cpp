#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main(int argc, const char *argv[]) {
  int cnt = 1, n;
  cin >> n;

  for (int i = 3; i <= 55555 && cnt <= n; ++i) {
    if (is_prime(i) && i % 5 == 1) {
      cout << i << '\n';
      cnt++;
    }
  }

  return 0;
}
