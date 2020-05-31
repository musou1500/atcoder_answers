#include <bits/stdc++.h>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;
int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> va(n), vb(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i] >> vb[i];
  }

  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end(), greater<ll>());

  if (n % 2 == 0) {
    int mid_idx = n / 2 - 1;
    int mid_idx2 = n / 2;
    ll a = va[mid_idx] + va[mid_idx + 1];
    ll b = vb[mid_idx] + vb[mid_idx + 1];
    ll ans = abs(b - a) + 1;
    cout << ans << '\n';
  } else {
    int mid_idx = (n + 1) / 2 - 1;
    ll ans = abs(vb[mid_idx] - va[mid_idx]) + 1ll;
    cout << ans << '\n';
  }

  return 0;
}
