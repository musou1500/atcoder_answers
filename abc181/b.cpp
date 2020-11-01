#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  
  ll ans = 0;

  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    ll s1 = (1 + b) * b / 2;
    ll s2 = (1 + a-1) * (a-1) / 2;
    ans += (s1-s2);
  }

  cout << ans << '\n';
  return 0;
}
