#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<queue<int>> tbl(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      int a;
      cin >> a;
      tbl[i].push(a - 1);
    }
  }

  int ans = -1;
  vector<int> cnt(n, 0);
  while (true) {
    bool all_skip = true, ok = false;
    for (int i = 0; i < n; ++i) {
      if (tbl[i].empty()) {
        continue;
      }

      all_skip = false;

      int opponent = tbl[i].front();
      if (i == tbl[opponent].front()) {
        ok = true;
        tbl[opponent].pop();
        tbl[i].pop();
        cnt[i] = cnt[opponent] = max(cnt[i], cnt[opponent]) + 1;
      }
    }

    if (all_skip) {
      ans = *max_element(cnt.begin(), cnt.end());
      break;
    }

    if (!ok) {
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}

