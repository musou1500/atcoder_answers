#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n;
  cin >> n;
  if (n == 0) {
    cout << 0 << '\n';
    return 0;
  }

  string ans;
  while (n != 0) {
    ll r = n % 2;
    if (r < 0) {
      r += 2;
    }

    ans += '0' + r;
    n = (n - r) / -2;
  }

  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}
