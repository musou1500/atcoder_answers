#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  long long n, m;
  cin >> n >> m;
  long long ans = 1900 * m + (n - m) * 100;
  cout << ans * (1ll << m) << '\n';
  return 0;
}
