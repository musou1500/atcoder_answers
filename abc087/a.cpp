#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x, a, b;
  cin >> x >> a >> b;
  x -= a;
  x -= b * (x / b);
  cout << x << '\n';
  return 0;
}
