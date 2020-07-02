#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> vab(m);
  vector<set<int>> va(n);
  for (auto &p : vab) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    p.first = a;
    p.second = b;
    va[a].insert(b);
    va[b].insert(a);
  }

  bool ans = false;
  for (auto &s : va[0]) {
    if (va[s].count(n - 1) > 0) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << '\n';

  return 0;
}
