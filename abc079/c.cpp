#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  char a, b, c, d;
  cin >> a >> b >> c >> d;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        int sum = a - '0';
        int d1 = b - '0';
        int d2 = c - '0';
        int d3 = d - '0';
        sum += (i == 0) ? -d1 : d1;
        sum += (j == 0) ? -d2 : d2;
        sum += (k == 0) ? -d3 : d3;

        if (sum == 7) {
          string ans = "";
          ans += a;
          ans += i == 0 ? '-' : '+';
          ans += b;
          ans += j == 0 ? '-' : '+';
          ans += c;
          ans += k == 0 ? '-' : '+';
          ans += d;
          ans += "=7";
          cout << ans << '\n';
          return 0;
        }
      }
    }
  }
  return 0;
}
