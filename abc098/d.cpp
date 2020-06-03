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

  auto c2 = [](ll n) -> ll { return n * (n - 1) / 2 + n; };

  ll acc = 0, ans = 0;
  int l, r;
  l = r = 0;
  while (l < va.size()) {
    int cnt = 0, prev_r = r;
    while (r < va.size() && va[r] + acc == (va[r] ^ acc)) {
      acc ^= va[r];
      r++;
      cnt++;
    }

    ans += c2(r - l) - c2(prev_r - l);

    acc ^= va[l];
    l++;
  }

  cout << ans << '\n';
  return 0;
}
