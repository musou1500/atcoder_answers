#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<pair<ll, ll>> pts(n);
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].first >> pts[i].second;
  }

  bool ans = false;
  for (int i = 0; i < n && !ans; ++i) {
    for (int j = 0; j < n && !ans; ++j) {
      if (i == j) {
        continue;
      }

      for (int k = 0; k < n && !ans; ++k) {
        if (i == k || j == k) {
          continue;
        }

        vector<pair<ll, ll>> vp{
          pts[i], pts[j], pts[k]
        };

        sort(vp.begin(), vp.end());
        ll x_dist1 = abs(vp[1].first - vp[0].first);
        ll x_dist2 = abs(vp[2].first - vp[1].first);
        if (( vp[1].second - vp[0].second ) * x_dist2 == ( vp[2].second - vp[1].second ) * x_dist1) {
          ans = true;
        }
      }
    }
  }

  if (ans) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}
