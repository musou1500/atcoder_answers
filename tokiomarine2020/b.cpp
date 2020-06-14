#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main(int argc, const char *argv[]) {
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;

  ll dist = abs(a - b);
  ll sp = (v - w) * t;
  cout << (sp >= dist ? "YES" : "NO") << '\n';

  return 0;
}
