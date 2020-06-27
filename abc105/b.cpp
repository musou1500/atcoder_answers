#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  bool ans = false;
  for (int i = 0; i <= n / 4; ++i) {
    if ((n - i * 4) % 7 == 0) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
