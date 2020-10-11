#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w, k;
  cin >> h >> w >> k;

  vector<string> c(h);
  for (int i = 0; i < h; ++i) {
    cin >> c[i];
  }

  int ans = 0;
  for (int bit_y = 0; bit_y < (1 << h); ++bit_y) {
    for (int bit_x = 0; bit_x < (1 << w); ++bit_x) {
      int b_cnt = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          bool y_sel = bit_y & (1 << i);
          bool x_sel = bit_x & (1 << j);
          if (y_sel || x_sel || c[i][j] == '.') {
            continue;
          }

          b_cnt++;
        }
      }

      if (b_cnt == k) {
        ans++;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
