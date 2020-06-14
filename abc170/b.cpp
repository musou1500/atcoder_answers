#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x, y;
  cin >> x >> y;

  bool ans = false;
  // 亀がi匹
  for (int i = 0; i <= x; ++i) {
    if (i * 4 + (x - i) * 2 == y) {
      ans = true;
      break;
    }
  }

  if (ans) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}
