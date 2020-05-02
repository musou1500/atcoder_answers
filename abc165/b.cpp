#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  using ull = unsigned long long;
  ull x;
  cin >> x;

  ull ans = 0, n = 100;
  while (n < x) {
    ans++;
    n = n * 1.01;
  }

  cout << ans << '\n';
  return 0;
}
