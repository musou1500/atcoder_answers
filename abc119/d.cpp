#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll find_nearest(vector<ll> &vs, ll x) {
  auto it1 = lower_bound(vs.begin(), vs.end(), x);
  auto it2 = lower_bound(vs.rbegin(), vs.rend(), x, greater<ll>());
  if (it1 == vs.end() || it2 == vs.rend()) {
    return it1 != vs.end() ? *it1 : *it2;
  } else {
    ll p1 = *it1, p2 = *it2;
    return (p1 - x < x - p2) ? p1 : p2;
  }
}

ll solve(vector<ll> &vs, vector<ll> &vt, ll x) {
  // まず右に進むとき
  ll dist_r = -1;
  auto rit_s = lower_bound(vs.begin(), vs.end(), x);
  auto rit_t = lower_bound(vt.begin(), vt.end(), x);
  if (rit_s != vs.end() || rit_t != vt.end()) {
    ll rp_s = rit_s == vs.end() ? 1e13 : *rit_s;
    ll rp_t = rit_t == vt.end() ? 1e13 : *rit_t;
    dist_r = min(rp_s - x, rp_t - x);
    if (rp_s - x < rp_t - x) {
      dist_r += abs(find_nearest(vt, rp_s) - rp_s);
    } else {
      dist_r += abs(find_nearest(vs, rp_t) - rp_t);
    }
  }

  // まず左に進むとき
  ll dist_l = -1;
  auto lit_s = lower_bound(vs.rbegin(), vs.rend(), x, greater<ll>());
  auto lit_t = lower_bound(vt.rbegin(), vt.rend(), x, greater<ll>());
  if (lit_s != vs.rend() || lit_t != vt.rend()) {
    auto lp_s = lit_s == vs.rend() ? 0 : *lit_s;
    auto lp_t = lit_t == vt.rend() ? 0 : *lit_t;

    dist_l = min(x - lp_s, x - lp_t);
    if (x - lp_s < x - lp_t) {
      dist_l += abs(find_nearest(vt, lp_s) - lp_s);
    } else {
      dist_l += abs(find_nearest(vs, lp_t) - lp_t);
    }
  }

  if (dist_l < 0 || dist_r < 0) {
    return dist_l < 0 ? dist_r : dist_l;
  } else {
    return min(dist_l, dist_r);
  }
}

int main(int argc, const char *argv[]) {
  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> vs(a), vt(b), vx(q);
  for (auto &s : vs) cin >> s;
  for (auto &t : vt) cin >> t;
  for (auto &x : vx) cin >> x;

  sort(vs.begin(), vs.end());
  sort(vt.begin(), vt.end());

  for (auto &x : vx) {
    cout << solve(vs, vt, x) << '\n';
  }
  return 0;
}
