#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c, x;
  cin >> a >> b >> c >> x;

  int ans = 0;
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      for (int k = 0; k <= c; ++k) {
        int sum = 500 * i + 100 * j + 50 * k;
        if (sum == x) {
          ans++;
        }
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
