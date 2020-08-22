#include <bits/stdc++.h>

using namespace std;

class Dijkstra {
  using QItem = pair<int, int>;

 public:
  vector<int> minDistance(vector<array<int, 3>> &edges, int n, int src) {
    vector<int> costs(n, -1);
    costs[src] = 0;

    // 各ノードの隣接ノードとその距離を初期化
    vector<vector<pair<int, int>>> distances(n);
    for (auto &edge : edges) {
      int n1 = edge[0], n2 = edge[1], d = edge[2];
      distances[n1].push_back({n2, d});
    }

    vector<bool> used(n, false);
    priority_queue<QItem, vector<QItem>, greater<QItem>> q;
    q.push({0, src});

    while (!q.empty()) {
      // 未確定で，コストの一番低いノードを選択する
      auto [min_cost, min_idx] = q.top();
      q.pop();

      // 選択したノードは確定とする
      used[min_idx] = true;

      // 選択したノードの隣接ノードについて，そのコストを再計算する
      for (auto &p : distances[min_idx]) {
        int new_cost = min_cost + p.second;
        if (costs[p.first] < 0 || costs[p.first] > new_cost) {
          costs[p.first] = new_cost;
          q.push({new_cost, p.first});
        }
      }
    }

    return costs;
  }
};

int main(int argc, const char *argv[]) {
  int h, w, ch, cw, dh, dw;
  cin >> h >> w >> ch >> cw >> dh >> dw;
  ch--, cw--, dh--, dw--;
  vector<string> maze(h);
  for (int i = 0; i < h; ++i) {
    cin >> maze[i];
  }

  vector<array<int, 3>> edges;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (maze[i][j] == '#') {
        continue;
      }

      int min_y = max(0, i - 2), max_y = min(h - 1, i + 2);
      int min_x = max(0, j - 2), max_x = min(w - 1, j + 2);
      for (int i2 = min_y; i2 <= max_y; ++i2) {
        for (int j2 = min_x; j2 <= max_x; ++j2) {
          if (i2 == i && j2 == j) {
            continue;
          }

          if (maze[i2][j2] == '#') {
            continue;
          }

          int dist = abs(i2 - i) + abs(j2 - j);
          int cost = dist <= 1 ? 0 : 1;
          // cout << i << ' ' << j << ' ' << i2 << ' ' << j2 << ' ' << cost
          // << '\n';
          edges.push_back({i * w + j, i2 * w + j2, cost});
          edges.push_back({i2 * w + j2, i * w + j, cost});
        }
      }
    }
  }

  Dijkstra d;
  vector<int> min_dists = d.minDistance(edges, h * w, ch * w + cw);
  int ans = min_dists[dh * w + dw];
  cout << ans << '\n';
  return 0;
}
