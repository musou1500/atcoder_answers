#include <bits/stdc++.h>

using namespace std;

bool is_matched(vector<string> &va, vector<string> &vb, int y, int x) {
  bool ans = true;
  for (int i = 0; i < va.size() && ans; ++i) {
    for (int j = 0; j < va.size(); ++j) {
      if (vb[i + y][j + x] != va[i][j]) {
        ans = false;
        break;
      }
    }
  }

  return ans;
}

bool solve(vector<string> &va, vector<string> &vb) {
  if (va.size() > vb.size()) {
    return solve(vb, va);
  }

  int diff = vb.size() - va.size();
  bool ans = false;
  for (int i = 0; i <= diff && !ans; ++i) {
    for (int j = 0; j <= diff; ++j) {
      // 始点をi,jに固定
      if (is_matched(va, vb, i, j)) {
        ans = true;
        break;
      }
    }
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<string> va(n), vb(m);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> vb[i];
  }

  cout << (solve(va, vb) ? "Yes" : "No") << '\n';
  return 0;
}
