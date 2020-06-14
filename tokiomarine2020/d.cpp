#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(vector<pair<ll, ll>> &vw, int offset, ll w_lim) {
  if (offset == 0) {
    return vw[0].second > w_lim ? 0 : vw[0].second;
  }

  return max(
      solve(vw, w_lim, offset / 2),
      solve(vw, w_lim - vw[offset].second, offset / 2) + vw[offset].first);
}

int main(int argc, const char *argv[]) {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vw(n);
  for (int i = 0; i < n; ++i) {
    cin >> vw[i].first >> vw[i].second;
  }

  ll q;
  cin >> q;
  vector<pair<ll, ll>> vq(q);
  for (int i = 0; i < q; ++i) {
    cin >> vq[i].first >> vq[i].second;
  }

  for (auto &q : vq) {
    solve(vw, q.first, q.second);
  }

  return 0;
}
