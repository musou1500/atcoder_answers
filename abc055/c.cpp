#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, m;
  cin >> n >> m;

  if (n * 2 >= m) {
    cout << m / 2 << '\n';
  } else {
    ll ans = n;
    m -= n * 2;
    cout << ans + (m / 4) << '\n';
  }
  return 0;
}
