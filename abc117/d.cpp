#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, k;
  cin >> n >> k;

  vector<bitset<40>> va;
  for (ll i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    va.emplace_back(a);
  }

  ll pow2 = 1, bit_size = 1;
  while (pow2 <= k) {
    pow2 *= 2;
    bit_size++;
  }
  pow2 /= 2;
  bit_size--;

  ll x = 0;
  for (int i = bit_size - 1; i >= 0; --i, pow2 /= 2) {
    int cnt1 = 0;
    for (int j = 0; j < va.size(); j++) {
      cnt1 += va[j].test(i);
    }

    if (va.size() - cnt1 > cnt1 && x + pow2 <= k) {
      x += pow2;
    }
  }

  ll ans = 0;
  for (int i = 0; i < va.size(); ++i) {
    ll a = va[i].to_ullong();
    ans += a ^ x;
  }

  cout << ans << '\n';
  return 0;
}
