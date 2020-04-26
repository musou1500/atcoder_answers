#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> vertices(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    vertices[a].push_back({i, b});
    vertices[b].push_back({i, a});
  }

  vector<int> ans(n - 1, 0);
  vector<bool> visited(n, false);

  // ノード番号，親の色
  queue<pair<int, int>> q;
  q.push({0, 0});

  int max_n = 0;
  while (!q.empty()) {
    auto idx = q.front().first, p_color = q.front().second;
    q.pop();
    if (visited[idx]) {
      continue;
    }

    visited[idx] = true;

    // v.first: 辺のインデックス
    // v.second: 辺の向かう先
    int color = 1;
    for (auto v : vertices[idx]) {
      if (p_color == color) {
        color++;
      }

      if (ans[v.first] == 0) {
        q.push({v.second, color});
        ans[v.first] = color;
        color++;
      }
    }

    max_n = max(max_n, color - 1);
  }

  cout << max_n << '\n';
  for (auto c : ans) {
    cout << c << '\n';
  }
}
