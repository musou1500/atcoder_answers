#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w, k;
  cin >> h >> w >> k;

  vector<vector<int>> vs(h);
  for (int i = 0; i < vs.size(); ++i) {
    for (int j = 0; j < w; ++j) {
      char c;
      cin >> c;
      if (c == '#') {
        vs[i].push_back(j);
      }
    }
  }

  vector<vector<int>> ans(h, vector<int>(w));
  vector<int> last_results, buf;
  int cur = 1;
  for (int i = 0; i < h; ++i) {
    if (vs[i].empty()) {
      if (!last_results.empty()) {
        ans[i] = last_results;
      } else {
        buf.push_back(i);
      }

      continue;
    }

    int cnt = vs[i].size();
    fill(ans[i].begin(), ans[i].end(), cur++);
    for (int j = 1; j < cnt; ++j) {
      fill(ans[i].begin() + vs[i][j], ans[i].end(), cur++);
    }

    for (int j = 0; j < buf.size(); ++j) {
      ans[buf[j]] = ans[i];
    }

    buf.clear();

    last_results = ans[i];
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << ans[i][j] << (j == w - 1 ? '\n' : ' ');
    }
  }

  return 0;
}
