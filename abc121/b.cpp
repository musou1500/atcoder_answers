#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m, c;
  cin >> n >> m >> c;

  vector<int> vb(m);
  for (int i = 0; i < m; i++) {
    cin >> vb[i];
  }

  vector<vector<int>> va(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> va[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int sum = c;
    for (int j = 0; j < m; j++) {
      sum += va[i][j] * vb[j];
    }

    if (sum > 0) {
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}
