#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> vab(m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }

    vab[i].first = a;
    vab[i].second = b;
  }

  sort(vab.begin(), vab.end());
  int l = vab[0].first, r = vab[0].second;

  int ans = 0;
  for (int i = 1; i < m; ++i) {
    int tmp_l = l, tmp_r = r;
    l = max(l, vab[i].first);
    r = min(r, vab[i].second);
    // cout << r - l << '\n';
    if (r - l < 1) {
      ans++;
      l = vab[i].first;
      r = vab[i].second;
    }

    if (i == m - 1) {
      ans++;
    }
  }

  // cout << l << ' ' << r << '\n';
  cout << max(1, ans) << '\n';
  return 0;
}
