#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  vector<string> m(h);
  for (int i = 0; i < h; ++i) {
    cin >> m[i];
  }

  bool ans = true;
  for (int i = 0; i < h && ans; ++i) {
    for (int j = 0; j < w && ans; ++j) {
      if (m[i][j] == '.') {
        continue;
      }

      bool ok = false;
      if (i != 0 && m[i - 1][j] == '#') {
        ok = true;
      }

      if (i != h - 1 && m[i + 1][j] == '#') {
        ok = true;
      }

      if (j != 0 && m[i][j - 1] == '#') {
        ok = true;
      }

      if (j != w - 1 && m[i][j + 1] == '#') {
        ok = true;
      }

      ans = ok;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
