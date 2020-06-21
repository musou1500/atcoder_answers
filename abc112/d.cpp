#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << m << '\n';
    return 0;
  }

  ll ans = 0;
  for (ll i = 1; i * i <= m; ++i) {
    if (m % i != 0) {
      continue;
    }

    if (m / i >= n && ans < i) {
      ans = i;
    }

    int j = m / i;
    if (m / j >= n && ans < j) {
      ans = j;
    }
  }

  cout << ans << '\n';
  return 0;
}

