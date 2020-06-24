#include <bits/stdc++.h>

using namespace std;

class Dijkstra {
  using QItem = pair<int, int>;

 public:
  vector<int> minDistance(vector<array<int, 3>> edges, int n, int src) {
    vector<int> costs(n, -1);
    costs[src] = 0;

    // 各ノードの隣接ノードとその距離を初期化
    vector<map<int, int>> distances(n);
    for (auto &edge : edges) {
      int n1 = edge[0], n2 = edge[1], d = edge[2];
      distances[n1][n2] = d;
      distances[n2][n1] = d;
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
      auto dist = distances[min_idx];
      for (auto p : dist) {
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
  int n, m, r;
  cin >> n >> m >> r;

  vector<int> vr(r);
  for (int i = 0; i < r; ++i) {
    cin >> vr[i];
    vr[i]--;
  }

  vector<array<int, 3>> edges(m);
  for (auto &e : edges) {
    cin >> e[0] >> e[1] >> e[2];
    e[0]--;
    e[1]--;
  }

  vector<vector<int>> costs(r);

  // costs[i][j]: vr[i]からjまで移動するときのコスト
  Dijkstra dijkstra;
  for (int i = 0; i < vr.size(); ++i) {
    costs[i] = dijkstra.minDistance(edges, n, vr[i]);
  }

  // 順番を全探索
  vector<int> order;
  for (int i = 0; i < r; ++i) {
    order.push_back(i);
  }

  int ans = -1;
  do {
    int cost_sum = 0;
    for (int i = 0; i < order.size() - 1; ++i) {
      cost_sum += costs[order[i]][vr[order[i + 1]]];
    }

    if (ans < 0 || cost_sum < ans) {
      ans = cost_sum;
    }
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << '\n';

  return 0;
}
