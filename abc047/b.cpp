#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int w, h, n;
  cin >> w >> h >> n;

  int t = h, b = 0, l = 0, r = w;
  for (int i = 0; i < n; ++i) {
    int x, y, a;
    cin >> x >> y >> a;
    switch (a) {
      case 1:
        l = max(l, x);
        break;
      case 2:
        r = min(r, x);
        break;
      case 3:
        b = max(b, y);
        break;
      default:
        t = min(t, y);
        break;
    }
  }

  cout << max(0, r - l) * max(0, t - b) << '\n';
  return 0;
}
