#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string ans;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      char c;
      cin >> c;
      if (i == j) {
        ans += c;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
