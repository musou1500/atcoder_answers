#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    va[i] -= i + 1;
  }

  sort(va.begin(), va.end());

  ll mid = va[va.size() / 2], ans = 0;
  for (int i = 0; i < va.size(); ++i) {
    ans += abs(va[i] - mid);
  }

  cout << ans << '\n';

  return 0;
}

