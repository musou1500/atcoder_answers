#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  ll c;
  cin >> n >> c;

  vector<pair<ll, ll>> v_xv(n);
  vector<ll> f1(n + 1, 0), f2(n + 1, 0);
  ll v_sum = 0;
  for (int i = 0; i < n; i++) {
    auto &p = v_xv[i];
    cin >> p.first >> p.second;
    v_sum += p.second;
    f1[i + 1] = max(f1[i], v_sum - p.first);
    f2[i + 1] = max(f2[i], v_sum - p.first * 2);
  }

  ll ans = f1.back();
  v_sum = 0;
  for (int i = 0; i < n; ++i) {
    auto &p = *(v_xv.rbegin() + i);
    v_sum += p.second;
    ll l_dist = c - p.first;
    ll l_ans = v_sum - l_dist;
    if (i != n - 1) {
      ll r_max1 = *(f1.rbegin() + i + 1), r_max2 = *(f2.rbegin() + i + 1);
      l_ans += max(r_max1 - l_dist, r_max2);
    }

    ans = max(ans, l_ans);
  }

  cout << ans << '\n';

  return 0;
}
