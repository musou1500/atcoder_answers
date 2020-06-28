#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<vector<int>> g{{2}, {4, 6, 9, 11}, {1, 3, 5, 7, 8, 10, 12}};
  int x, y;
  cin >> x >> y;

  auto group = [&](int n) {
    int ans = 0;
    for (int i = 0; i < g.size(); ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        if (g[i][j] == n) {
          ans = i;
          break;
        }
      }
    }

    return ans;
  };

  cout << (group(x) == group(y) ? "Yes" : "No") << '\n';
  return 0;
}
