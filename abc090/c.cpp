#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  //
  using ll = long long;
  ll n, m;
  cin >> n >> m;
  if (n >= 2) {
    n -= 2;
  }

  if (m >= 2) {
    m -= 2;
  }

  cout << n * m << '\n';
  return 0;
}
