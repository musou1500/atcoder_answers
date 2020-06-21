#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<array<ll, 3>> vp;
  int idx;
  for (int i = 0; i < n; ++i) {
    int x, y, h;
    cin >> x >> y >> h;
    vp.push_back({x, y, h});
    if (h > 0) {
      idx = i;
    }
  }

  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      bool ok = true;
      ll ch = abs(i - vp[idx][0]) + abs(j - vp[idx][1]) + vp[idx][2];
      for (int k = 0; k < vp.size(); ++k) {
        auto &p = vp[k];
        ll h = max(0ll, ch - abs(p[0] - i) - abs(p[1] - j));
        if (h != p[2]) {
          ok = false;
          break;
        }
      }

      if (ok) {
        cout << i << ' ' << j << ' ' << ch << '\n';
        return 0;
      }
    }
  }

  return 0;
}
