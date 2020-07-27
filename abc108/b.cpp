#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int d1, d2;
  d1 = x2 - x1;
  d2 = y1 - y2;
  cout << x2 + d2 << ' ' << y2 + d1 << ' ' << x1 + d2 << ' ' << y1 + d1 << '\n';
  return 0;
}
