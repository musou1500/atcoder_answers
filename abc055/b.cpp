#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  ll md = 1e9 + 7;

  ll cur = 1;
  for (int i = 0; i < n; ++i) {
    cur = cur * (i + 1) % md;
  }

  cout << cur << '\n';

  return 0;
}
