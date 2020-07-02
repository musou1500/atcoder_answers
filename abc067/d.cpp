#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<vector<int>> g(n);
  vector<int> colors(n, -1);
  colors[0] = 1;
  colors[colors.size() - 1] = 0;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  stack<pair<int, int>> st;
  vector<int> vp(n, -1);
  st.push({0, 0});
  while (!st.empty()) {
    auto [idx, p] = st.top();
    st.pop();
    if (vp[idx] >= 0) {
      continue;
    }

    vp[idx] = p;
    for (auto ch : g[idx]) {
      st.push({ch, idx});
    }
  }

  int cur = n - 1;
  vector<int> vpath;
  while (cur != 0) {
    cur = vp[cur];
    if (cur != 0) {
      vpath.push_back(cur);
    }
  }

  int turns = vpath.size() / 2;
  int turn_f = turns + vpath.size() % 2, turn_s = turns;
  for (int i = 0; i < vpath.size(); ++i) {
    colors[vpath[i]] = i >= turn_s;
  }

  auto dfs = [&](int c, int init) {
    stack<int> st;
    vector<bool> seen(n, false);
    st.push(init);
    int ans = 0;
    while (!st.empty()) {
      auto idx = st.top();
      st.pop();
      if (seen[idx] || (colors[idx] != -1 && colors[idx] != c)) {
        continue;
      }

      ans += colors[idx] == -1;
      seen[idx] = true;
      colors[idx] = c;
      for (auto ch : g[idx]) {
        st.push(ch);
      }
    }

    return ans;
  };

  turn_f += dfs(1, 0);
  turn_s += dfs(0, n - 1);

  cout << (turn_f == turn_s || turn_s > turn_f ? "Snuke" : "Fennec") << '\n';
  return 0;
}
