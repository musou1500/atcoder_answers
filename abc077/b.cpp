#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i * i <= n; ++i) {
    ans = i * i;
  }

  cout << ans << '\n';
  return 0;
}
