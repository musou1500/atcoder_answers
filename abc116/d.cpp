#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  map<int, vector<ll>> sushi;
  for (int i = 0; i < n; ++i) {
    int t;
    ll d;
    cin >> t >> d;
    sushi[t].push_back(d);
  }

  vector<ll> g1, g2;
  for (auto &p : sushi) {
    auto &vd = p.second;
    auto max_it = max_element(vd.begin(), vd.end());
    g1.push_back(*max_it);
    for (auto it = vd.begin(); it != vd.end(); it++) {
      if (it != max_it) {
        g2.push_back(*it);
      }
    }
  }

  sort(g1.begin(), g1.end(), greater<ll>());
  sort(g2.begin(), g2.end(), greater<ll>());

  vector<ll> g1_psum{0}, g2_psum{0};
  partial_sum(g1.begin(), g1.end(), back_inserter(g1_psum));
  partial_sum(g2.begin(), g2.end(), back_inserter(g2_psum));

  ll ans = 0;
  for (ll i = 1; i <= k && i <= g1.size(); ++i) {
    if (k - i >= g2_psum.size()) {
      continue;
    }

    ans = max(ans, i * i + g1_psum[i] + g2_psum[k - i]);
  }

  cout << ans << '\n';

  return 0;
}
