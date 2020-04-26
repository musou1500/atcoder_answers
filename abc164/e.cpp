#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minDistance(vector<array<int, 3>> edges, int src, int dest) {
    unordered_map<int, int> costs{{src, 0}};
    set<int> used_nodes;

    // 各ノードの隣接ノードとその距離を初期化
    unordered_map<int, unordered_map<int, int>> distances;
    for (auto &edge : edges) {
      int n1 = edge[0], n2 = edge[1], d = edge[2];
      distances[n1][n2] = d;
      distances[n2][n1] = d;
    }

    while (true) {
      // 未確定で，コストの一番低いノードを選択する
      int min_idx = -1;
      for (auto it = costs.begin(); it != costs.end(); it++) {
        bool unused = used_nodes.find(it->first) == used_nodes.end();
        if (unused && (min_idx == -1 || it->second < costs[min_idx])) {
          min_idx = it->first;
        }
      }

      if (min_idx == -1) {
        break;
      }

      // 選択したノードは確定とする
      used_nodes.insert(min_idx);

      // 選択したノードの隣接ノードについて，そのコストを再計算する
      auto dist = distances[min_idx];
      auto cost = costs[min_idx];
      for (auto it = dist.begin(); it != dist.end(); it++) {
        int new_cost = cost + dist[it->first];
        if (costs.count(it->first) == 0 || costs[it->first] > new_cost) {
          costs[it->first] = new_cost;
        }
      }
    }

    if (costs.count(dest) == 0) {
      return -1;
    }

    return costs[dest];
  }
};

// int main(int argc, const char *argv[]) {
// vector<array<int, 3>> edges{
// {0, 1, 5}, {0, 2, 4}, {0, 3, 2}, {1, 2, 2}, {2, 3, 3},
// {1, 5, 6}, {2, 4, 2}, {3, 4, 6}, {4, 5, 4},
// };
// int src = 0, dest = 5;

// Solution s;
// cout << s.minDistance(edges, src, dest) << "\n";
// return 0;
// }

int main(int argc, const char *argv[]) {
  int n, m, s;
  cin >> n >> m >> s;
  vector<vector<int>> vertices(n);
  vector<int> va(m), vb(m), vc(n), vd(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v >> va[i] >> vb[i];
    vertices[u].push_back({v});
    vertices[v].push_back({u});
  }

  for (int i = 0; i < n; i++) {
    cin >> vc[i] >> vd[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2499; j++) {
      auto next_idx = vertices.size();
      vertices.push_back({});
    }
  }

  return 0;
}
