#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> vt(n);
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ll t;
    cin >> t;
    ans = lcm(ans, t);
  }

  cout << ans << '\n';
  return 0;
}
