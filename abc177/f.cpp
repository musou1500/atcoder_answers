#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  //
  ll h, w;
  cin >> h >> w;

  vector<pair<ll, ll>> vab(h);
  for (int i = 0; i < h; ++i) {
    cin >> vab[i].first >> vab[i].second;
    vab[i].first--;
    vab[i].second--;
  }

  ll x, y, dist;
  x = y = dist = 0;
  if (vab[0].first <= x && x <= vab[0].second) {
    x = vab[0].second + 1;
    dist = vab[0].second;
  }

  for (int i = 0; i <= h; ++i) {
    auto [l, r] = vab[y];
    if (x >= w || y >= h + 1) {
      cout << -1 << '\n';
      continue;
    }

    if (y > 0) {
      cout << dist << '\n';
    }

    // 降りられない
    if (l <= x && x <= r) {
      dist += r - x + 1;
      x = r + 1;
    }

    y++;
    dist++;
  }

  return 0;
}
