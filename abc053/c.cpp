#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll x;
  cin >> x;
  ll ans = x / 11;
  x -= 11 * ans;
  ans *= 2;

  bool p = true;
  while (x > 0) {
    if (p) {
      x -= 6;
    } else {
      x -= 5;
    }

    p = !p;
    ans++;
  }

  cout << ans << '\n';
  return 0;
}
