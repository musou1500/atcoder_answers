#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int src, dest;
    cin >> src >> dest;
    src--;
    dest--;
    graph[src].push_back(dest);
  }

  int s, t;
  cin >> s >> t;
  s--;
  t--;

  int ans = -1;
  vector<vector<bool>> visited(n, vector<bool>(3, false));
  queue<pair<int, int>> q;
  q.push({s, 0});
  while (!q.empty()) {
    int node_idx = q.front().first, dist = q.front().second;
    q.pop();

    if (visited[node_idx][dist % 3]) {
      continue;
    }

    visited[node_idx][dist % 3] = true;

    if (dist % 3 == 0 && node_idx == t) {
      ans = dist / 3;
      break;
    }

    for (auto &neighbor : graph[node_idx]) {
      q.push({neighbor, dist + 1});
    }
  }

  cout << ans << '\n';

  return 0;
}

