#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int k, a, b;
  cin >> k >> a >> b;
  bool ans = false;
  for (int i = a; i <= b; ++i) {
    if (i % k == 0) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "OK" : "NG") << '\n';
  return 0;
}
