#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, k;
  cin >> n >> k;

  ll cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (k % 2 == 0 && i % k == k / 2) {
      cnt2++;
    }

    if (i % k == 0) {
      cnt1++;
    }
  }

  auto pow3 = [](ll x) { return x * x * x; };
  cout << pow3(cnt1) + pow3(cnt2) << '\n';
  return 0;
}
