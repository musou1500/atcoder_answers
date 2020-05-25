#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int max_n, rest;
  if (a >= b && a >= c) {
    max_n = a;
    rest = b + c;
  } else if (b >= a && b >= c) {
    max_n = b;
    rest = a + c;
  } else {
    max_n = c;
    rest = a + b;
  }

  for (int i = 0; i < k; ++i) {
    max_n *= 2;
  }

  cout << max_n + rest << '\n';
  return 0;
}
