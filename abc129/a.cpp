#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int p, q, r;
  cin >> p >> q >> r;
  cout << p + q + r - max({p, q, r}) << '\n';
  return 0;
}
