#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, k;
  cin >> n >> k;
  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  ll left = 1, right = *max_element(va.begin(), va.end());
  auto check = [](vector<ll> &va, ll mid, ll k) {
    ll cnt = 0;
    for (int i = 0; i < va.size(); ++i) {
      ll a = va[i];
      cnt += a / mid - (a % mid == 0);
    }

    return cnt <= k;
  };

  while (left < right) {
    ll mid = (left + right) / 2;
    if (check(va, mid, k)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  cout << right << '\n';

  return 0;
}
