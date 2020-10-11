#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x, y;
  cin >> x >> y;
  int ans = 0;
  if (x <= 3) {
    ans += 300000 - (x - 1) * 100000;
  }

  if (y <= 3) {
    ans += 300000 - (y - 1) * 100000;
  }

  if (x == 1 && y == 1) {
    ans += 400000;
  }

  cout << ans << '\n';
  return 0;
}
