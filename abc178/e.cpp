#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<array<ll, 2>> vp(n);

  for (auto &p : vp) {
    ll x, y;
    cin >> x >> y;
    p[0] = x - y;
    p[1] = x + y;
  }

  ll ans = 0;
  for (int d = 0; d < 2; ++d) {
    ll max_n, min_n;
    max_n = min_n = vp.front()[d];
    for (auto &p : vp) {
      max_n = max(p[d], max_n);
      min_n = min(p[d], min_n);
    }

    ans = max(ans, max_n - min_n);
  }

  cout << ans << '\n';
  return 0;
}
