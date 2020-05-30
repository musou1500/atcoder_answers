#include <bits/stdc++.h>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<ll> va(n + 1);
  for (int i = 0; i < n + 1; ++i) {
    cin >> va[i];
  }

  ll a_sum = accumulate(va.begin(), va.end(), 0ll);

  ll base = 1;
  ll ans = 0;
  bool ok = true;
  for (int i = 0; i < va.size(); ++i, base = min(base * 2ll, a_sum)) {
    ans += base;
    base -= va[i];
    a_sum -= va[i];

    if (base < 0) {
      ok = false;
      break;
    }
  }

  ans += base;

  if (!ok) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }

  return 0;
}
