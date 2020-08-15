#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll x, k, d;
  cin >> x >> k >> d;
  if (x < 0) {
    x *= -1;
  }

  ll k2 = min(x / d, k);
  if (k2 + 1 <= k && abs(x - k2 * d) > abs(x - (k2 + 1) * d)) {
    k2++;
  }

  ll x2 = x - k2 * d;
  if ((k - k2) % 2 == 0) {
    cout << abs(x2) << '\n';
  } else {
    cout << min(abs(x2 + d), abs(x2 - d)) << '\n';
  }

  return 0;
}
