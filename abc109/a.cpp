#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;

  bool ans = false;
  for (int i = 1; i <= 3; ++i) {
    if (a * b * i % 2 == 1) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
