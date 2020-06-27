#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> va(n), vb(m);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> vb[i];
  }

  vector<ll> csum_a{0}, csum_b;
  partial_sum(va.begin(), va.end(), back_inserter(csum_a));
  partial_sum(vb.begin(), vb.end(), back_inserter(csum_b));

  ll ans = 0;

  // aからi冊読む
  for (int i = 0; i <= va.size(); ++i) {
    ll a_sum = csum_a[i];
    if (a_sum > k) {
      break;
    }

    auto it =
        lower_bound(csum_b.rbegin(), csum_b.rend(), k - a_sum, greater<ll>());
    ans = max(ans, i + m - distance(csum_b.rbegin(), it));
  }

  cout << ans << '\n';

  return 0;
}
