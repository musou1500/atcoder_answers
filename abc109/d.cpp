#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  vector<vector<int>> m(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> m[i][j];
    }
  }

  vector<array<int, 4>> ans;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w - 1; ++j) {
      if (m[i][j] % 2 == 0) {
        continue;
      }

      m[i][j]--;
      m[i][j + 1]++;
      ans.push_back({i + 1, j + 1, i + 1, j + 2});
    }
  }

  for (int i = 0; i < h - 1; ++i) {
    if (m[i][w - 1] % 2 == 0) {
      continue;
    }

    m[i][w - 1]--;
    m[i + 1][w - 1]++;
    ans.push_back({i + 1, w, i + 2, w});
  }

  cout << ans.size() << '\n';
  for (auto &a : ans) {
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << '\n';
  }

  return 0;
}
