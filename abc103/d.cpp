#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> vab(m);
  for (auto &p : vab) {
    cin >> p.first >> p.second;
  }

  sort(vab.begin(), vab.end());

  int l = vab[0].first, r = vab[0].second, ans = 1;
  for (int i = 1; i < m; ++i) {
    l = max(l, vab[i].first);
    r = min(r, vab[i].second);

    if (r - l < 1) {
      ans++;
      l = vab[i].first;
      r = vab[i].second;
    }
  }

  cout << ans << '\n';
  return 0;
}
