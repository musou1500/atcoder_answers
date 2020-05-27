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

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += va[i] - 1;
  }

  cout << ans << '\n';
  return 0;
}
