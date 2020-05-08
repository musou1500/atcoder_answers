#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool check(vector<ll> &va, vector<ll> &vf, ll x, ll k) {
  for (int i = 0; k >= 0 && i < va.size(); ++i) {
    k -= max(0ll, va[i] - x / vf[i]);
  }

  return k >= 0;
}

int main(int argc, const char *argv[]) {
  int n;
  ll k;
  cin >> n >> k;

  vector<ll> va(n), vf(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> vf[i];
  }

  sort(va.begin(), va.end());
  sort(vf.begin(), vf.end(), greater<ll>());

  ll max_n = va.front() * vf.front();
  for (int i = 1; i < n; ++i) {
    max_n = max(max_n, va[i] * vf[i]);
  }

  ll left = 0, right = max_n;
  while (left < right) {
    ll mid = (left + right) / 2;
    if (check(va, vf, mid, k)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  cout << right << '\n';

  return 0;
}
