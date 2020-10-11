#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ll j = 1;
    while (i * j <= n) {
      if (i * j < n) {
        ans++;
      }
      j++;
    }
  }

  cout << ans << '\n';
  return 0;
}
