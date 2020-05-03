#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<int> vh(n);
  for (int i = 0; i < n; ++i) {
    cin >> vh[i];
  }

  vector<vector<int>> t(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].push_back(vh[b]);
    t[b].push_back(vh[a]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    sort(t[i].begin(), t[i].end());
    auto it = lower_bound(t[i].begin(), t[i].end(), vh[i]);
    if (it == t[i].end()) {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}
