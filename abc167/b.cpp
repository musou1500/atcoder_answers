#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  ll a, b, c, k;
  cin >> a >> b >> c >> k;

  ll ans = min(k, a);
  k = max(0ll, k - (a + b));
  ans -= k;
  cout << ans << '\n';
  return 0;
}
