#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  ll k;
  cin >> k;

  ll n = 50;
  ll div = k / n, mod = k % n;

  // cnt[i]: A_iに対する操作回数
  vector<ll> cnt(n);
  for (ll i = 0; i < n; ++i) {
    cnt[i] = div + (i < mod);
  }

  vector<ll> va(n);
  for (ll i = 0; i < n; ++i) {
    // A_iはいくつ増えるか
    ll sum = 0;
    for (ll j = 0; j < n; ++j) {
      if (i != j) {
        sum += cnt[j];
      }
    }

    va[i] = n * (cnt[i] + 1) - sum - 1;
  }

  cout << va.size() << '\n';
  for (ll i = 0; i < va.size(); ++i) {
    cout << va[i] << (i == va.size() - 1 ? '\n' : ' ');
  }

  return 0;
}

