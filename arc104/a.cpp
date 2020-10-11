#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  for (int i = -500; i < 500; ++i) {
    for (int j = -500; j < 500; ++j) {
      if (i + j == a && i - j == b) {
        cout << i << ' ' << j << '\n';
        break;
      }
    }
  }
  return 0;
}
