#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  vector<ll> csum;
  partial_sum(va.begin(), va.end(), back_inserter(csum));

  ll ans = -1;
  for (int i = 0; i < 2; ++i) {
    ll diff = 0, cnts = 0;
    for (int j = 0; j < n; ++j) {
      ll a = csum[j] + diff;
      if (j % 2 == i && a >= 0) {
        diff -= a + 1;
        cnts += a + 1;
      } else if (j % 2 != i && a <= 0) {
        diff += -a + 1;
        cnts += -a + 1;
      }
    }

    if (ans < 0 || ans > cnts) {
      ans = cnts;
    }
  }

  cout << ans << '\n';

  return 0;
}
