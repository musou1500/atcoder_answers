#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  int q, k;
  cin >> q >> k;
  k--;

  vector<ll> costs(n);
  vector<bool> seen(n, false);
  stack<pair<int, ll>> st;
  st.push({k, 0});
  while (!st.empty()) {
    auto [idx, cost] = st.top();
    st.pop();
    if (seen[idx]) {
      continue;
    }

    costs[idx] = cost;
    seen[idx] = true;

    for (auto &child : g[idx]) {
      st.push({child.first, cost + child.second});
    }
  }

  vector<ll> ans;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ans.push_back(costs[x] + costs[y]);
  }

  for (auto a : ans) {
    cout << a << '\n';
  }

  return 0;
}
