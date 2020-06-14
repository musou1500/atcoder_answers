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

  sort(va.begin(), va.end());

  vector<bool> memo(va.back() + 1, false);

  for (int i = 0; i < va.size() - 1; i++) {
    ll a = va[i];
    for (ll j = a; j <= va.back(); j += a) {
      bool ex = binary_search(va.begin() + i + 1, va.end(), j);
      if (ex) {
        memo[j] = true;
      }
    }
  }

  ll ans = count_if(va.begin(), va.end(), [&](int a) { return !memo[a]; });
  cout << ans << '\n';
  return 0;
}
