#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> ans(n, -1);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    auto idx = q.front();
    q.pop();

    for (int i = 0; i < g[idx].size(); ++i) {
      if (ans[g[idx][i]] != -1 || g[idx][i] == 0) {
        continue;
      }

      ans[g[idx][i]] = idx;
      q.push(g[idx][i]);
    }
  }

  cout << "Yes" << '\n';
  for (int i = 1; i < n; ++i) {
    cout << ans[i] + 1 << '\n';
  }

  return 0;
}
