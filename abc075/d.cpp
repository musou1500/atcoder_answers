#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  vector<ll> vx(n), vy(n);
  vector<pair<ll, ll>> coords(n);
  for (int i = 0; i < n; i++) {
    cin >> vx[i] >> vy[i];
    coords[i].first = vx[i];
    coords[i].second = vy[i];
  }

  auto count_coords = [&](ll x1, ll x2, ll y1, ll y2) {
    return count_if(coords.begin(), coords.end(), [&](auto &c) {
      return x1 <= c.first && c.first <= x2 && y1 <= c.second && y2 >= c.second;
    });
  };

  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());

  ll ans = -1;
  for (int b = 0; b < n; ++b) {
    for (int t = b; t < n; ++t) {
      for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
          ll dy = vy[t] - vy[b], dx = vx[r] - vx[l];
          ll cnt = count_coords(vx[l], vx[r], vy[b], vy[t]);
          if (cnt < k) {
            continue;
          }

          ll area = dy * dx;
          ans = ans < 0 ? area : min(ans, area);
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
