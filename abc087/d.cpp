#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dfs(vector<vector<pair<int, int>>> &graph, vector<int> &vpos,
         vector<bool> &seen, int idx, int dist) {
  if (seen[idx]) {
    return vpos[idx] == dist;
  }

  seen[idx] = true;
  vpos[idx] = dist;
  return all_of(graph[idx].begin(), graph[idx].end(), [&](auto &node) {
    return dfs(graph, vpos, seen, node.first, dist + node.second);
  });
};

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    ll l, r, d;
    cin >> l >> r >> d;
    l--, r--;
    graph[l].push_back({r, d});
    graph[r].push_back({l, -d});
  }

  vector<bool> seen(n, false);
  vector<int> vpos(n, -1);
  bool ans = true;
  for (int i = 0; i < n && ans; ++i) {
    if (!seen[i]) {
      vpos[i] = 0;
      ans = dfs(graph, vpos, seen, i, 0);
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';

  return 0;
}
