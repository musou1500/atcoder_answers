#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, k;
  cin >> a >> b >> k;

  for (int i = a; i <= b; ++i) {
    if (i - a < k || b - i < k) {
      cout << i << '\n';
    }
  }
  return 0;
}
