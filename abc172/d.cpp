#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll x, ans = 0;
  cin >> x;
  for (int i = 1; i <= x; ++i) {
    ans += (x / i) * (2 * i + (x / i - 1) * i) / 2;
  }

  cout << ans << '\n';
  return 0;
}
