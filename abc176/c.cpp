#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  //
  int n;
  cin >> n;
  vector<ll> va(n), vb(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    if (i == 0) {
      vb[i] = va[i];
    } else {
      vb[i] = max(vb[i - 1], va[i]);
    }
  }

  ll ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    ans += max(0ll, vb[i] - va[i]);
  }

  cout << ans << '\n';
  return 0;
}
