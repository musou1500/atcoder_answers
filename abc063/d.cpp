#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> vh(n);
  for (int i = 0; i < n; ++i) {
    cin >> vh[i];
  }

  ll l = 1, r = pow(10, 9) + 1;
  while (l != r) {
    ll mid = (r + l) / 2;
    ll m = mid;
    for (int i = 0; i < n && m >= 0; ++i) {
      ll hp = vh[i] - mid * b;
      m -= max(0ll, hp / (a - b) + (hp % (a - b) > 0));
    }

    if (m < 0) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  cout << r << '\n';
}

