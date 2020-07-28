#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<ll> va(n), vb(n), vc(n);
  for (int i = 0; i < n; ++i) cin >> va[i];
  for (int i = 0; i < n; ++i) cin >> vb[i];
  for (int i = 0; i < n; ++i) cin >> vc[i];

  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  sort(vc.begin(), vc.end());

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    auto it_a = upper_bound(va.rbegin(), va.rend(), vb[i], greater<ll>());
    auto it_c = upper_bound(vc.begin(), vc.end(), vb[i]);

    ans += distance(it_a, va.rend()) * distance(it_c, vc.end());
  }

  cout << ans << '\n';

  return 0;
}
