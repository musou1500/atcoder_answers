#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<int>> va(n, vector<int>(m));
  vector<int> vc(n);
  for (int i = 0; i < n; ++i) {
    cin >> vc[i];
    for (int j = 0; j < m; ++j) {
      cin >> va[i][j];
    }
  }

  int ans = -1;
  for (int i = 0; i < (1 << n); ++i) {
    vector<int> vx(m, 0);
    int sum_price = 0;

    // 書籍 va_j, vc_j
    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) == 0) {
        continue;
      }

      sum_price += vc[j];
      for (int k = 0; k < m; ++k) {
        vx[k] += va[j][k];
      }
    }

    int min_n = *min_element(vx.begin(), vx.end());
    if (min_n < x) {
      continue;
    }

    if (ans == -1 || sum_price < ans) {
      ans = sum_price;
    }
  }

  cout << ans << '\n';
  return 0;
}
