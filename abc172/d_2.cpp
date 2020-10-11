#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll x, ans = 0;
  cin >> x;

  vector<ll> cnts(x + 1, 0);
  for (ll i = 1; i <= x; ++i) {
    for (ll j = i; j <= x; j += i) {
      cnts[j]++;
    }
  }

  for (int i = 1; i <= x; ++i) {
    ans += i * cnts[i];
  }

  cout << ans << '\n';
  return 0;
}
