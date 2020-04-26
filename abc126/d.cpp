#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<vector<pair<int, long long>>> tree(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    u--;
    v--;
    tree[u].push_back({v, w});
    tree[v].push_back({u, w});
  }

  stack<pair<int, long long>> st;
  vector<long long> results(n, 0);
  vector<bool> visited(n, false);
  st.push({0, 0});
  while (!st.empty()) {
    int node = st.top().first;
    long long d = st.top().second;
    st.pop();
    if (visited[node]) {
      continue;
    }

    results[node] = d;
    visited[node] = true;
    for (auto p : tree[node]) {
      st.push({p.first, p.second + d});
    }
  }

  for (auto r : results) {
    cout << r % 2 << '\n';
  }
  return 0;
}
