#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  long long a, b, n;
  cin >> a >> b >> n;

  // for (int i = 0; i < n; ++i) {
  // int res = floor(a * i / b) - a * floor(i / b);
  // cout << i << ' ' << res << '\n';
  // }
  long long x = min(n, b - 1);
  long long res = floor(a * x / b) - a * floor(x / b);
  cout << res << '\n';
  return 0;
}
