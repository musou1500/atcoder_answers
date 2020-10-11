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

  vector<ll> csum{0};
  partial_sum(va.begin(), va.end(), back_inserter(csum));

  ll ans = csum.back();
  for (int i = 0; i < n; ++i) {
    ll a = csum[i + 1];
    ll b = csum.back() - a;
    ans = min(ans, abs(a - b));
  }

  cout << ans << '\n';

  return 0;
}
