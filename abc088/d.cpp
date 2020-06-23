#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> s(h, vector<char>(w));
  int cnt = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> s[i][j];
      if (s[i][j] == '#') {
        cnt++;
      }
    }
  }

  // (i, j, cost)
  vector<vector<int>> costs(h, vector<int>(w, -1));
  queue<array<int, 3>> q;
  q.push({0, 0, 0});
  while (!q.empty()) {
    int i = q.front()[0], j = q.front()[1], cost = q.front()[2];
    q.pop();
    if (costs[i][j] != -1 || s[i][j] == '#') {
      continue;
    }

    costs[i][j] = cost;

    if (i != 0) {
      q.push({i - 1, j, cost + 1});
    }

    if (i != h - 1) {
      q.push({i + 1, j, cost + 1});
    }

    if (j != 0) {
      q.push({i, j - 1, cost + 1});
    }

    if (j != w - 1) {
      q.push({i, j + 1, cost + 1});
    }
  }

  if (costs[h - 1][w - 1] == -1) {
    cout << -1 << '\n';
  } else {
    cout << h * w - (costs[h - 1][w - 1] + 1) - cnt << '\n';
  }

  return 0;
}
