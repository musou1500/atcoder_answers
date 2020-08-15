#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, k;
  cin >> n >> k;

  vector<ll> vp(n), vc(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i];
    vp[i]--;
  }

  for (int i = 0; i < n; ++i) {
    cin >> vc[i];
  }

  vector<vector<ll>> pts_by_src(n);
  for (int i = 0; i < n; ++i) {
    vector<ll> used(n, false);
    ll cur = i, pt = 0;
    while (!used[cur]) {
      used[cur] = true;
      pt += vc[vp[cur]];
      pts_by_src[i].push_back(pt);
      cur = vp[cur];
    }
  }

  ll ans = pts_by_src.front().front();
  for (auto &pts : pts_by_src) {
    if (pts.back() <= 0) {
      ll sz = min(k, static_cast<ll>(pts.size()));
      ll pt = *max_element(pts.begin(), pts.begin() + sz);
      ans = max(ans, pt);
    } else {
      ll sz = k / pts.size(), md = k % pts.size();
      if (md == 0) {
        sz--;
      }

      ll pt = sz * pts.back();
      ll max_pt = md > 0 ? *max_element(pts.begin(), pts.begin() + md)
                         : *max_element(pts.begin(), pts.end());
      if (max_pt >= 0 || sz <= 0) {
        pt += max_pt;
      }

      ans = max(ans, pt);
    }
  }

  cout << ans << '\n';
  return 0;
}
