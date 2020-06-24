#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll l, r;
    cin >> l >> r;
    ans += (r - l + 1);
  }

  cout << ans << '\n';

  return 0;
}
