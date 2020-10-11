#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<array<ll, 3>> vc(n);
  for (auto &c : vc) {
    cin >> c[0] >> c[1] >> c[2];
  }

  ll ans = 0;
  for (int i = 0; i < (1 << 3); ++i) {
    sort(vc.begin(), vc.end(), [&](auto a, auto b) {
      ll sa = 0, sb = 0;
      for (int j = 0; j < 3; j++) {
        if (i & (1 << j)) {
          sa -= a[j];
          sb -= b[j];
        } else {
          sa += a[j];
          sb += b[j];
        }
      }

      return sa > sb;
    });

    ll sx = 0, sy = 0, sz = 0;
    for (int i = 0; i < m; ++i) {
      auto &c = vc[i];
      sx += c[0];
      sy += c[1];
      sz += c[2];
    }

    ll sum = abs(sx) + abs(sy) + abs(sz);
    ans = max(ans, sum);
  }

  cout << ans << '\n';

  return 0;
}
