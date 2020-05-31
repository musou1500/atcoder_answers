#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> va(n);
  bool z = false;
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    if (va[i] == 0) {
      z = true;
    }
  }

  if (z) {
    cout << 0 << '\n';
    return 0;
  }

  ll limit = pow(10, 18);
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    if (limit / ans < va[i]) {
      ans = -1;
      break;
    }

    ans *= va[i];
  }

  cout << ans << '\n';

  return 0;
}
