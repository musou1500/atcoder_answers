#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll x, y;
  cin >> x >> y;
  cout << (abs(x - y) > 1 ? "Alice" : "Brown") << '\n';
  return 0;
}
