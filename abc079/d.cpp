#include <bits/stdc++.h>

using namespace std;

int min_cost(array<array<int, 10>, 10> &c, int n, int st,
             vector<vector<int>> &memo) {
  if (n == 1) {
    return 0;
  }

  if (memo[n][st] < 0) {
    int ans = -1;
    for (int i = 0; i <= 9; ++i) {
      if (st & (1 << i)) {
        continue;
      }

      int cost = min_cost(c, i, st | (1 << i), memo) + c[n][i];
      if (ans < 0 || cost < ans) {
        ans = cost;
      }
    }

    memo[n][st] = ans;
  }

  return memo[n][st];
}

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  array<array<int, 10>, 10> c;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> c[i][j];
    }
  }

  vector<vector<int>> memo(10, vector<int>(2048, -1));
  int ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int a;
      cin >> a;
      if (a != -1) {
        ans += min_cost(c, a, 0, memo);
      }
    }
  }

  cout << ans << '\n';
}
