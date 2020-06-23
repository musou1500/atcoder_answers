#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w, cnt = 0;
  cin >> h >> w;

  vector<vector<char>> s(h, vector<char>(w));
  for (auto &r : s) {
    for (auto &c : r) {
      cin >> c;
      cnt += c == '#';
    }
  }

  vector<vector<int>> costs(h, vector<int>(w, -1));
  queue<array<int, 3>> q;
  q.push({0, 0, 0});
  while (!q.empty()) {
    auto [i, j, cost] = q.front();
    q.pop();
    if (i >= 0 && i < h && j >= 0 && j < w && costs[i][j] < 0 &&
        s[i][j] != '#') {
      costs[i][j] = cost;
      q.push({i - 1, j, cost + 1});
      q.push({i + 1, j, cost + 1});
      q.push({i, j - 1, cost + 1});
      q.push({i, j + 1, cost + 1});
    }
  }

  int cost = costs[h - 1][w - 1];
  if (cost < 0) {
    cout << -1 << '\n';
  } else {
    cout << h * w - (cost + 1) - cnt << '\n';
  }

  return 0;
}
