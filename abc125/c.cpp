#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  vector<int> gcds(n), rev_gcds(n);
  gcds[0] = va.front();
  rev_gcds[0] = va.back();
  for (int i = 1; i < va.size(); ++i) {
    gcds[i] = gcd(gcds[i - 1], va[i]);
    rev_gcds[i] = gcd(rev_gcds[i - 1], va[n - i - 1]);
  }

  auto except_gcd = [&](int idx) {
    if (idx == 0) {
      return rev_gcds[n - 2];
    } else if (idx == n - 1) {
      return gcds[n - 2];
    } else {
      return gcd(gcds[idx - 1], rev_gcds[n - idx - 2]);
    }
  };

  int ans = except_gcd(0);
  for (int i = 0; i < n; ++i) {
    ans = max(ans, except_gcd(i));
  }

  cout << ans << '\n';

  return 0;
}
