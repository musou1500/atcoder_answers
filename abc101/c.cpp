#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  int cur = 0, ans = 0;
  while (cur < n) {
    while (cur < n - 1 && va[cur + 1] == va.front()) {
      cur++;
    }

    bool diff = false;
    for (int i = cur; i < cur + k && i < va.size(); ++i) {
      if (va[i] != va.front()) {
        va[i] = va.front();
        diff = true;
      }
    }

    if (diff) {
      ans++;
    }

    cur = min(cur + k - 1, n);
  }

  cout << ans << '\n';

  return 0;
}
