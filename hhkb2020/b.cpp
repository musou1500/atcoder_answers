#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;
  vector<string> g(h);
  for (int i = 0; i < h; ++i) {
    cin >> g[i];
  }

  int ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w - 1; ++j) {
      if (g[i][j] == '.' && g[i][j + 1] == '.') {
        ans++;
      }
    }
  }

  for (int i = 0; i < h - 1; ++i) {
    for (int j = 0; j < w; ++j) {
      if (g[i][j] == '.' && g[i + 1][j] == '.') {
        ans++;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
