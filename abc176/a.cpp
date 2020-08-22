#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, x, t;
  cin >> n >> x >> t;
  int cnt = n / x + (n % x != 0);
  cout << cnt * t << '\n';
  return 0;
}
