#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  while (k > 0 && a >= b) {
    b *= 2;
    k--;
  }

  while (k > 0 && b >= c) {
    c *= 2;
    k--;
  }

  if (b > a && c > b) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}
