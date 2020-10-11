#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll a, b, k;
  cin >> a >> b >> k;
  for (int i = 0; i < k; ++i) {
    if (i % 2 == 0) {
      if (a % 2 == 1) {
        a--;
      }

      int dec = a / 2;
      b += dec;
      a -= dec;
    } else {
      if (b % 2 == 1) {
        b--;
      }

      int dec = b / 2;
      a += dec;
      b -= dec;
    }
  }

  cout << a << ' ' << b << '\n';
  return 0;
}
